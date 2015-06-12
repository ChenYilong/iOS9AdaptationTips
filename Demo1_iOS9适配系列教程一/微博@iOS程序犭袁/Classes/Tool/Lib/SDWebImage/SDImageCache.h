/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "SDWebImageCompat.h"

typedef NS_ENUM(NSInteger, SDImageCacheType) {
    /**
     * The image wasn't available the SDWebImage caches, but was downloaded from the web.
     * 不使用 SDWebImage 缓存，从网络下载
     */
    SDImageCacheTypeNone,
    /**
     * The image was obtained from the disk cache.
     * 磁盘缓存图像
     */
    SDImageCacheTypeDisk,
    /**
     * The image was obtained from the memory cache.
     * 内存缓存图像
     */
    SDImageCacheTypeMemory
};

typedef void(^SDWebImageQueryCompletedBlock)(UIImage *image, SDImageCacheType cacheType);

typedef void(^SDWebImageCheckCacheCompletionBlock)(BOOL isInCache);

typedef void(^SDWebImageCalculateSizeBlock)(NSUInteger fileCount, NSUInteger totalSize);

/**
 * SDImageCache maintains a memory cache and an optional disk cache. Disk cache write operations are performed
 * asynchronous so it doesn’t add unnecessary latency to the UI.
 * <br />SDImageCache 维护一个内存缓存以及一个"可选"的磁盘缓存。磁盘缓存的写入操作是异步执行，因此不会造成 UI 的延迟
 */
@interface SDImageCache : NSObject

/**
 * Decompressing images that are downloaded and cached can improve peformance but can consume lot of memory.
 * Defaults to YES. Set this to NO if you are experiencing a crash due to excessive memory consumption.
 */
@property (assign, nonatomic) BOOL shouldDecompressImages;

/**
 * The maximum "total cost" of the in-memory image cache. The cost function is the number of pixels held in memory.
 * <br />最大内存图像缓存值，以像素值为单位，默认数值为0
 */
@property (assign, nonatomic) NSUInteger maxMemoryCost;

/**
 * The maximum length of time to keep an image in the cache, in seconds
 * <br />缓存图像最长时间，以秒为单位，默认一周
 */
@property (assign, nonatomic) NSInteger maxCacheAge;

/**
 * The maximum size of the cache, in bytes.
 * <br />缓存图像总大小，以字节为单位，默认数值为0
 */
@property (assign, nonatomic) NSUInteger maxCacheSize;

/**
 * Returns global shared cache instance
 * <br />返回全局的缓存实例
 *
 * @return SDImageCache global instance
 * <br />SDImageCache 全局实例
 */
+ (SDImageCache *)sharedImageCache;

/**
 * Init a new cache store with a specific namespace
 * <br />使用指定的命名空间实例化一个新的缓存存储
 *
 * @param ns The namespace to use for this cache store
 * <br />缓存存储使用的命名空间
 */
- (id)initWithNamespace:(NSString *)ns;

-(NSString *)makeDiskCachePath:(NSString*)fullNamespace;

/**
 * Add a read-only cache path to search for images pre-cached by SDImageCache
 * Useful if you want to bundle pre-loaded images with your app
 * <br />如果希望在 bundle 中存储预加载的图像，可以添加一个只读的缓存路径，让 SDImageCache 从 Bundle 中搜索预先缓存的图像
 *
 * @param path The path to use for this read-only cache path
 * <br />只读缓存路径(mainBundle中的全路径)
 */
- (void)addReadOnlyCachePath:(NSString *)path;

/**
 * Store an image into memory and disk cache at the given key.
 * <br />使用指定的键将图像保存到内存和磁盘缓存
 *
 * @param image The image to store
 * <br />要保存的图像
 * @param key   The unique image cache key, usually it's image absolute URL
 * <br />唯一的图像缓存键，通常是图像的完整 URL
 */
- (void)storeImage:(UIImage *)image forKey:(NSString *)key;

/**
 * Store an image into memory and optionally disk cache at the given key.
 * <br />使用指定的键将图像保存到内存和可选的磁盘缓存
 *
 * @param image  The image to store
 * <br />要保存的图像
 * @param key    The unique image cache key, usually it's image absolute URL
 * <br />唯一的图像缓存键，通常是图像的完整 URL
 * @param toDisk Store the image to disk cache if YES
 * <br />如果是 YES，则将图像缓存到磁盘
 */
- (void)storeImage:(UIImage *)image forKey:(NSString *)key toDisk:(BOOL)toDisk;

/**
 * Store an image into memory and optionally disk cache at the given key.
 * <br />使用指定的键将图像保存到内存和可选的磁盘缓存
 *
 * @param image       The image to store
 * <br />要保存的图像
 * @param recalculate BOOL indicates if imageData can be used or a new data should be constructed from the UIImage
 * <br />是否直接使用 imageData，还是从 UIImage 重新构造数据
 * @param imageData   The image data as returned by the server, this representation will be used for disk storage
 *                    instead of converting the given image object into a storable/compressed image format in order
 *                    to save quality and CPU
 * <br />从服务器返回图像的二进制数据，表示直接保存到磁盘，而不是将给定的图像对象转换成一个可存储/可压缩的图像格式，从而保留图片质量并降低 CPU 开销
 * @param key         The unique image cache key, usually it's image absolute URL
 * <br />唯一的图像缓存键，通常是图像的完整 URL
 * @param toDisk      Store the image to disk cache if YES
 * <br />如果是 YES，则将图像缓存到磁盘
 */
- (void)storeImage:(UIImage *)image recalculateFromImage:(BOOL)recalculate imageData:(NSData *)imageData forKey:(NSString *)key toDisk:(BOOL)toDisk;

/**
 * Query the disk cache asynchronously.
 * <br />异步查询磁盘缓存
 *
 * @param key The unique key used to store the wanted image
 * <br />保存图像的唯一键
 */
- (NSOperation *)queryDiskCacheForKey:(NSString *)key done:(SDWebImageQueryCompletedBlock)doneBlock;

/**
 * Query the memory cache synchronously.
 * <br />同步查询内存缓存
 *
 * @param key The unique key used to store the wanted image
 */
- (UIImage *)imageFromMemoryCacheForKey:(NSString *)key;

/**
 * Query the disk cache synchronously after checking the memory cache.
 * <br />查询内存缓存之后同步查询磁盘缓存
 *
 * @param key The unique key used to store the wanted image
 */
- (UIImage *)imageFromDiskCacheForKey:(NSString *)key;

/**
 * Remove the image from memory and disk cache synchronously
 * <br />同步从内存和磁盘缓存删除图像
 *
 * @param key The unique image cache key
 */
- (void)removeImageForKey:(NSString *)key;


/**
 * Remove the image from memory and disk cache synchronously
 * <br />同步从内存和磁盘缓存删除图像
 *
 * @param key             The unique image cache key
 * @param completion      An block that should be executed after the image has been removed (optional)
 */
- (void)removeImageForKey:(NSString *)key withCompletion:(SDWebImageNoParamsBlock)completion;

/**
 * Remove the image from memory and optionally disk cache synchronously
 * <br />同步从内存和可选磁盘缓存删除图像
 *
 * @param key      The unique image cache key
 * @param fromDisk Also remove cache entry from disk if YES
 *                 如果是 YES，则从磁盘删除缓存
 */
- (void)removeImageForKey:(NSString *)key fromDisk:(BOOL)fromDisk;

/**
 * Remove the image from memory and optionally disk cache synchronously
 * <br />同步从内存和可选磁盘缓存删除图像
 *
 * @param key             The unique image cache key
 * @param fromDisk        Also remove cache entry from disk if YES
 * @param completion      An block that should be executed after the image has been removed (optional)
 *                        完成删除之后的块代码回调
 */
- (void)removeImageForKey:(NSString *)key fromDisk:(BOOL)fromDisk withCompletion:(SDWebImageNoParamsBlock)completion;

/**
 * Clear all memory cached images
 * <br />删除所有内存缓存的图像
 */
- (void)clearMemory;

/**
 * Clear all disk cached images. Non-blocking method - returns immediately.
 * <br />删除所有磁盘缓存的图像。
 *
 * @param completion    An block that should be executed after cache expiration completes (optional)
 *                      删除操作后的块代码回调（可选）
 */
- (void)clearDiskOnCompletion:(SDWebImageNoParamsBlock)completion;

/**
 * Clear all disk cached images
 * <br />删除所有磁盘缓存的图像
 *
 * @see clearDiskOnCompletion:
 */
- (void)clearDisk;

/**
 * Remove all expired cached image from disk. Non-blocking method - returns immediately.
 * <br />从磁盘中删除所有过期的缓存图像。
 *
 * @param completionBlock An block that should be executed after cache expiration completes (optional)
 */
- (void)cleanDiskWithCompletionBlock:(SDWebImageNoParamsBlock)completionBlock;

/**
 * Remove all expired cached image from disk
 * <br />从磁盘中删除所有过期的缓存图像。
 * @see cleanDiskWithCompletionBlock:
 */
- (void)cleanDisk;

/**
 * Get the size used by the disk cache
 * <br />获得磁盘缓存占用空间
 */
- (NSUInteger)getSize;

/**
 * Get the number of images in the disk cache
 * <br />获得缓存图像的个数
 */
- (NSUInteger)getDiskCount;

/**
 * Asynchronously calculate the disk cache's size.
 * <br />异步计算磁盘缓存的大小
 */
- (void)calculateSizeWithCompletionBlock:(SDWebImageCalculateSizeBlock)completionBlock;

/**
 *  Async check if image exists in disk cache already (does not load the image)
 *  <br />异步检查图像是否已经在磁盘缓存中存在（不加载图像）
 *
 *  @param key             the key describing the url
 *  @param completionBlock the block to be executed when the check is done.
 *  @note the completion block will be always executed on the main queue
 */
- (void)diskImageExistsWithKey:(NSString *)key completion:(SDWebImageCheckCacheCompletionBlock)completionBlock;

/**
 *  Check if image exists in disk cache already (does not load the image)
 *  <br />异步检查图像是否已经在磁盘缓存中存在（不加载图像）
 *
 *  @param key the key describing the url
 *
 *  @return YES if an image exists for the given key
 */
- (BOOL)diskImageExistsWithKey:(NSString *)key;

/**
 *  Get the cache path for a certain key (needs the cache path root folder)
 *  <br />获得指定 key 对应的缓存路径(需要指定缓存路径的根目录)
 *
 *  @param key  the key (can be obtained from url using cacheKeyForURL)
 *  @param path the cach path root folder
 *
 *  @return the cache path
 */
- (NSString *)cachePathForKey:(NSString *)key inPath:(NSString *)path;

/**
 *  Get the default cache path for a certain key
 *  <br />获得指定 key 的默认缓存路径
 *
 *  @param key the key (can be obtained from url using cacheKeyForURL)
 *
 *  @return the default cache path
 */
- (NSString *)defaultCachePathForKey:(NSString *)key;

@end
