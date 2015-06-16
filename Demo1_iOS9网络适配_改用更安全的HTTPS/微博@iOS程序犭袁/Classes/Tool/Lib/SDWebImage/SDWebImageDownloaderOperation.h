/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "SDWebImageDownloader.h"
#import "SDWebImageOperation.h"

extern NSString *const SDWebImageDownloadStartNotification;
extern NSString *const SDWebImageDownloadReceiveResponseNotification;
extern NSString *const SDWebImageDownloadStopNotification;
extern NSString *const SDWebImageDownloadFinishNotification;

@interface SDWebImageDownloaderOperation : NSOperation <SDWebImageOperation>

/**
 * The request used by the operation's connection.
 * <br />操作的连接使用的请求
 */
@property (strong, nonatomic, readonly) NSURLRequest *request;


@property (assign, nonatomic) BOOL shouldDecompressImages;

/**
 * Whether the URL connection should consult the credential storage for authenticating the connection. `YES` by default.
 * <br />URL 连接是否询问保存连接身份验证的凭据，默认是 `YES`
 *
 * This is the value that is returned in the `NSURLConnectionDelegate` method `-connectionShouldUseCredentialStorage:`.
 * <br />这是在 `NSURLConnectionDelegate` 的 `-connectionShouldUseCredentialStorage:` 方法中的返回值
 */
@property (nonatomic, assign) BOOL shouldUseCredentialStorage;

/**
 * The credential used for authentication challenges in `-connection:didReceiveAuthenticationChallenge:`.
 * <br />在 `-connection:didReceiveAuthenticationChallenge:` 方法中身份验证使用的凭据
 *
 * This will be overridden by any shared credentials that exist for the username or password of the request URL, if present.
 * <br />如果存在请求 URL 的用户名或密码的共享凭据，此凭据会被覆盖
 */
@property (nonatomic, strong) NSURLCredential *credential;

/**
 * The SDWebImageDownloaderOptions for the receiver.
 * <br />下载选项
 */
@property (assign, nonatomic, readonly) SDWebImageDownloaderOptions options;

/**
 * The expected size of data.
 */
@property (assign, nonatomic) NSInteger expectedSize;

/**
 * The response returned by the operation's connection.
 */
@property (strong, nonatomic) NSURLResponse *response;

/**
 *  Initializes a `SDWebImageDownloaderOperation` object
 *  <br />初始化一个 `SDWebImageDownloaderOperation` 对象
 *
 *  @see SDWebImageDownloaderOperation
 *
 *  @param request        the URL request
 *  <br />请求
 *  @param options        downloader options
 *  <br />下载选项
 *  @param progressBlock  the block executed when a new chunk of data arrives. 
 *  <br />新的数据块到达时执行的 block(下载进度)
 *                        @note the progress block is executed on a background queue
 *  @note progress block 在后台队列之行
 *  @param completedBlock the block executed when the download is done. 
 *  <br />下载结束后执行的 block
 *                        @note the completed block is executed on the main queue for success. If errors are found, there is a chance the block will be executed on a background queue
 *  @note 如果下载成功，completion block 在主队列执行。如果出现错误，block 可能会在后台队列执行
 *  @param cancelBlock    the block executed if the download (operation) is cancelled
 *  <br />如果下载(操作)被取消，执行的 block
 *
 *  @return the initialized instance
 *  <br />初始化的实例
 */
- (id)initWithRequest:(NSURLRequest *)request
              options:(SDWebImageDownloaderOptions)options
             progress:(SDWebImageDownloaderProgressBlock)progressBlock
            completed:(SDWebImageDownloaderCompletedBlock)completedBlock
            cancelled:(SDWebImageNoParamsBlock)cancelBlock;

@end
