/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SDWebImageCompat.h"
#import "SDWebImageOperation.h"
#import "SDWebImageDownloader.h"
#import "SDImageCache.h"

typedef NS_OPTIONS(NSUInteger, SDWebImageOptions) {
    /**
     * By default, when a URL fail to be downloaded, the URL is blacklisted so the library won't keep trying.
     * 默认情况下，当一个 URL 下载失败，会将该 URL 放在黑名单中，不再尝试下载
     *
     * This flag disable this blacklisting.
     * 此标记取消黑名单
     */
    SDWebImageRetryFailed = 1 << 0,

    /**
     * By default, image downloads are started during UI interactions, this flags disable this feature,
     * 默认情况下，在 UI 交互时也会启动图像下载，此标记取消这一特性
     *
     * leading to delayed download on UIScrollView deceleration for instance.
     * 会推迟到滚动视图停止滚动之后再继续下载
     * 备注：NSURLConnection 的网络下载事件监听的运行循环模式是 NSDefaultRunLoopMode
     */
    SDWebImageLowPriority = 1 << 1,

    /**
     * This flag disables on-disk caching
     * 此标记取消磁盘缓存
     */
    SDWebImageCacheMemoryOnly = 1 << 2,

    /**
     * This flag enables progressive download, the image is displayed progressively during download as a browser would do.
     * 此标记允许渐进式下载，就像浏览器中那样，下载过程中，图像会逐步显示出来
     *
     * By default, the image is only displayed once completely downloaded.
     * 默认情况下，图像会在下载完成后一次性显示
     */
    SDWebImageProgressiveDownload = 1 << 3,

    /**
     * Even if the image is cached, respect the HTTP response cache control, and refresh the image from remote location if needed.
     * 即使图像被缓存，遵守 HTPP 响应的缓存控制，如果需要，从远程刷新图像
     *
     * The disk caching will be handled by NSURLCache instead of SDWebImage leading to slight performance degradation.
     * 磁盘缓存将由 NSURLCache 处理，而不是 SDWebImage，这会对性能有轻微的影响
     *
     * This option helps deal with images changing behind the same request URL, e.g. Facebook graph api profile pics.
     * 此选项有助于处理同一个请求 URL 的图像发生变化
     *
     * If a cached image is refreshed, the completion block is called once with the cached image and again with the final image.
     * 如果缓存的图像被刷新，会调用一次 completion block，并传递最终的图像
     *
     * Use this flag only if you can't make your URLs static with embeded cache busting parameter.
     * 仅在无法使用嵌入式缓存清理参数确定图像 URL 时，使用此标记
     */
    SDWebImageRefreshCached = 1 << 4,

    /**
     * In iOS 4+, continue the download of the image if the app goes to background. This is achieved by asking the system for
     * 在 iOS 4+，当 App 进入后台后仍然会继续下载图像。这是向系统请求额外的后台时间以保证下载请求完成的
     *
     * extra time in background to let the request finish. If the background task expires the operation will be cancelled.
     * 如果后台任务过期，请求将会被取消
     */
    SDWebImageContinueInBackground = 1 << 5,

    /**
     * Handles cookies stored in NSHTTPCookieStore by setting
     * 通过设置
     * NSMutableURLRequest.HTTPShouldHandleCookies = YES;
     * 处理保存在 NSHTTPCookieStore 中的 cookies
     */
    SDWebImageHandleCookies = 1 << 6,

    /**
     * Enable to allow untrusted SSL ceriticates.
     * 允许不信任的 SSL 证书
     *
     * Useful for testing purposes. Use with caution in production.
     * 可以出于测试目的使用，在正式产品中慎用
     */
    SDWebImageAllowInvalidSSLCertificates = 1 << 7,

    /**
     * By default, image are loaded in the order they were queued. This flag move them to
     * 默认情况下，图像会按照在队列中的顺序被加载，此标记会将它们移动到队列前部立即被加载
     *
     * the front of the queue and is loaded immediately instead of waiting for the current queue to be loaded (which 
     * 而不是等待当前队列被加载，等待队列加载会需要一段时间
     * could take a while).
     */
    SDWebImageHighPriority = 1 << 8,
    
    /**
     * By default, placeholder images are loaded while the image is loading. This flag will delay the loading
     * 默认情况下，在加载图像时，占位图像已经会被加载。而此标记会延迟加载占位图像，直到图像已经完成加载
     *
     * of the placeholder image until after the image has finished loading.
     */
    SDWebImageDelayPlaceholder = 1 << 9,

    /**
     * We usually don't call transformDownloadedImage delegate method on animated images,
     * 通常不会在可动画的图像上调用 transformDownloadedImage 代理方法，因为大多数转换代码会破坏动画文件
     *
     * as most transformation code would mangle it.
     * Use this flag to transform them anyway.
     * 使用此标记尝试转换
     */
    SDWebImageTransformAnimatedImage = 1 << 10,
};

typedef void(^SDWebImageCompletionBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL);

typedef void(^SDWebImageCompletionWithFinishedBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished, NSURL *imageURL);

typedef NSString *(^SDWebImageCacheKeyFilterBlock)(NSURL *url);


@class SDWebImageManager;

@protocol SDWebImageManagerDelegate <NSObject>

@optional

/**
 * Controls which image should be downloaded when the image is not found in the cache.
 *
 * @param imageManager The current `SDWebImageManager`
 * @param imageURL     The url of the image to be downloaded
 *
 * @return Return NO to prevent the downloading of the image on cache misses. If not implemented, YES is implied.
 */
- (BOOL)imageManager:(SDWebImageManager *)imageManager shouldDownloadImageForURL:(NSURL *)imageURL;

/**
 * Allows to transform the image immediately after it has been downloaded and just before to cache it on disk and memory.
 * NOTE: This method is called from a global queue in order to not to block the main thread.
 *
 * @param imageManager The current `SDWebImageManager`
 * @param image        The image to transform
 * @param imageURL     The url of the image to transform
 *
 * @return The transformed image object.
 */
- (UIImage *)imageManager:(SDWebImageManager *)imageManager transformDownloadedImage:(UIImage *)image withURL:(NSURL *)imageURL;

@end

/**
 * The SDWebImageManager is the class behind the UIImageView+WebCache category and likes.
 * <br />SDWebImageManager 是 UIImageView+WebCache 等分类后台工作的类
 *
 * It ties the asynchronous downloader (SDWebImageDownloader) with the image cache store (SDImageCache).
 * <br />是异步下载器 (SDWebImageDownloader) 和图像缓存存储 (SDImageCache) 之间的纽带
 *
 * You can use this class directly to benefit from web image downloading with caching in another context than
 * a UIView.
 * <br />可以直接使用此类实现 web 图像下载
 *
 * Here is a simple example of how to use SDWebImageManager:
 * <br />以下是如何使用 SDWebImageManager 的示例代码
 *
 * @code

SDWebImageManager *manager = [SDWebImageManager sharedManager];
[manager downloadImageWithURL:imageURL
                      options:0
                     progress:nil
                    completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished, NSURL *imageURL) {
                        if (image) {
                            // do something with image
                        }
                    }];

 * @endcode
 */
@interface SDWebImageManager : NSObject

@property (weak, nonatomic) id <SDWebImageManagerDelegate> delegate;

@property (strong, nonatomic, readonly) SDImageCache *imageCache;
@property (strong, nonatomic, readonly) SDWebImageDownloader *imageDownloader;

/**
 * The cache filter is a block used each time SDWebImageManager need to convert an URL into a cache key. This can
 * be used to remove dynamic part of an image URL.
 * <br />"缓存过滤器"是一个 block，用于每次 SDWebImageManager 需要将一个 URL 转换成一个缓存的键值，可用于删除图像 URL 中动态的部分
 *
 * The following example sets a filter in the application delegate that will remove any query-string from the
 * URL before to use it as a cache key:
 * <br />以下示例在 application 代理中设置一个过滤器，该过滤器会在将 URL 当作缓存键值之前，从 URL 中删除请求字符串
 *
 * @code

[[SDWebImageManager sharedManager] setCacheKeyFilter:^(NSURL *url) {
    url = [[NSURL alloc] initWithScheme:url.scheme host:url.host path:url.path];
    return [url absoluteString];
}];

 * @endcode
 */
@property (nonatomic, copy) SDWebImageCacheKeyFilterBlock cacheKeyFilter;

/**
 * Returns global SDWebImageManager instance.
 * <br />返回全局的 SDWebImageManager 实例(单例)
 *
 * @return SDWebImageManager shared instance
 */
+ (SDWebImageManager *)sharedManager;

/**
 * Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 * <br />如果不存在缓存下载指定 URL 的图像，否则返回缓存的图像
 *
 * @param url            The URL to the image
 * @param options        A mask to specify options to use for this request
 * @param progressBlock  A block called while image is downloading
 * <br />下载进度回调，后台线程
 * @param completedBlock A block called when operation has been completed.
 * <br />操作完成回调，主线程
 *
 *   This parameter is required.
 *   <br />此参数是必须的
 *
 *   This block has no return value and takes the requested UIImage as first parameter.
 *   <br />此block没有返回值，第一个参数是请求的 UIImage
 *   In case of error the image parameter is nil and the second parameter may contain an NSError.
 *   <br />如果出现错误，image 参数是 nil，并且第二个参数会包含一个 NSError
 *
 *   The third parameter is an `SDImageCacheType` enum indicating if the image was retrived from the local cache
 *   or from the memory cache or from the network.
 *   <br />第三个参数是一个 `SDImageCacheType` 枚举，标示该图像是从本地缓存加载，还是从内存缓存加载，还是从网络下载
 *
 *   The last parameter is set to NO when the SDWebImageProgressiveDownload option is used and the image is 
 *   downloading. This block is thus called repetidly with a partial image. When image is fully downloaded, the
 *   block is called a last time with the full image and the last parameter set to YES.
 *   <br />第四个参数，图像下载完成后返回 YES，如果使用 SDWebImageProgressiveDownload 选项，同时只获取到部分图片时，返回 NO
 *
 * @return Returns an NSObject conforming to SDWebImageOperation. Should be an instance of SDWebImageDownloaderOperation
 */
- (id <SDWebImageOperation>)downloadImageWithURL:(NSURL *)url
                                         options:(SDWebImageOptions)options
                                        progress:(SDWebImageDownloaderProgressBlock)progressBlock
                                       completed:(SDWebImageCompletionWithFinishedBlock)completedBlock;

/**
 * Saves image to cache for given URL
 * <br />将图像保存成指定 URL 对应的缓存
 *
 * @param image The image to cache
 * @param url   The URL to the image
 *
 */

- (void)saveImageToCache:(UIImage *)image forURL:(NSURL *)url;

/**
 * Cancel all current opreations
 * <br />取消当前所有操作
 */
- (void)cancelAll;

/**
 * Check one or more operations running
 * <br />检查一个或多个操作是否正在运行
 */
- (BOOL)isRunning;

/**
 *  Check if image has already been cached
 *  <br />检查图像是否已经被缓存
 *
 *  @param url image url
 *
 *  @return if the image was already cached
 */
- (BOOL)cachedImageExistsForURL:(NSURL *)url;

/**
 *  Check if image has already been cached on disk only
 *  <br />检查图像是否存在磁盘缓存（此方法仅针对磁盘进行检查，只要存在就返回YES）
 *
 *  @param url image url
 *
 *  @return if the image was already cached (disk only)
 */
- (BOOL)diskImageExistsForURL:(NSURL *)url;

/**
 *  Async check if image has already been cached
 *  <br />异步检查图像是否已经存在缓存
 *
 *  @param url              image url
 *  @param completionBlock  the block to be executed when the check is finished
 *  
 *  @note the completion block is always executed on the main queue
 */
- (void)cachedImageExistsForURL:(NSURL *)url
                     completion:(SDWebImageCheckCacheCompletionBlock)completionBlock;

/**
 *  Async check if image has already been cached on disk only
 *  <br />异步检查图像是否已经存在缓存
 *
 *  @param url              image url
 *  @param completionBlock  the block to be executed when the check is finished
 *
 *  @note the completion block is always executed on the main queue
 */
- (void)diskImageExistsForURL:(NSURL *)url
                   completion:(SDWebImageCheckCacheCompletionBlock)completionBlock;


/**
 *Return the cache key for a given URL
 * <br />返回指定 URL 的缓存键值，就是 URL 字符串
 */
- (NSString *)cacheKeyForURL:(NSURL *)url;

@end


#pragma mark - Deprecated

typedef void(^SDWebImageCompletedBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType) __deprecated_msg("Block type deprecated. Use `SDWebImageCompletionBlock`");
typedef void(^SDWebImageCompletedWithFinishedBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished) __deprecated_msg("Block type deprecated. Use `SDWebImageCompletionWithFinishedBlock`");


@interface SDWebImageManager (Deprecated)

/**
 *  Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 *  @deprecated This method has been deprecated. Use `downloadImageWithURL:options:progress:completed:`
 */
- (id <SDWebImageOperation>)downloadWithURL:(NSURL *)url
                                    options:(SDWebImageOptions)options
                                   progress:(SDWebImageDownloaderProgressBlock)progressBlock
                                  completed:(SDWebImageCompletedWithFinishedBlock)completedBlock __deprecated_msg("Method deprecated. Use `downloadImageWithURL:options:progress:completed:`");

@end
