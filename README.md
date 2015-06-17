# iOS9AdaptationTips



iOS9适配系列教程

## 1. Demo1_iOS9网络适配_改用更安全的HTTPS


> English



How to deal with the SSL in iOS9，One solution is to  do like:
 ![enter image description here][3]

  [3]: https://github.com/ChenYilong/iOS9AdaptationTips/blob/master/Demo1_iOS9网络适配_改用更安全的HTTPS/微博%40iOS程序犭袁/http问题.gif


As the [Apple][1] say :
  [1]: https://developer.apple.com/library/prerelease/ios/releasenotes/General/WhatsNewIniOS/Articles/iOS9.html#//apple_ref/doc/uid/TP40016198-DontLinkElementID_13
  
 ![enter image description here][2]
  [2]: https://i.imgur.com/dCD1fBB.png
  
  
   ![enter image description here][4]

  [4]: https://i.imgur.com/Tc0fS6p.jpg
   ![enter image description here][5]

  [5]: https://i.imgur.com/v2Tskwh.jpg
  
iOS 9 and OSX 10.11 require TLSv1.2 SSL for all hosts you plan to request data from unless you specify exception domains in your app's Info.plist file.

The syntax for the Info.plist configuration looks like this:

    <key>NSAppTransportSecurity</key>
    <dict>
      <key>NSExceptionDomains</key>
      <dict>
        <key>yourserver.com</key>
        <dict>
          <!--Include to allow subdomains-->
          <key>NSIncludesSubdomains</key>
          <true/>
          <!--Include to allow insecure HTTP requests-->
          <key>NSTemporaryExceptionAllowsInsecureHTTPLoads</key>
          <true/>
          <!--Include to specify minimum TLS version-->
          <key>NSTemporaryExceptionMinimumTLSVersion</key>
          <string>TLSv1.1</string>
        </dict>
      </dict>
    </dict>

If your application (a third-party web browser, for instance) needs to connect to arbitrary hosts, you can configure it like this:

    <key>NSAppTransportSecurity</key>
    <dict>
        <!--Connect to anything (this is probably BAD)-->
	    <key>NSAllowsArbitraryLoads</key>
	    <true/>
    </dict>

If you're having to do this, it's probably best to update your servers to use TLSv1.2 and SSL, if they're not already doing so. This should be considered a temporary workaround.

As of today, the prerelease documentation makes no mention of any of these configuration options in any specific way. Once it does, I'll update the answer to link to the relevant documentation.

##2.Demo2_iOS9新特性_更灵活的后台定位
If you're using CoreLocation framework in your app in Xcode7(pre-released),and you may notice that there is a newly added property called allowsBackgroundLocationUpdates in CLLocationManager class.

This new property is explained in the WWDC session ["What's New in Core Location"][6].
 ![enter image description here][7]

  [7]: https://i.imgur.com/pvVh1fx.png
The default value is `NO` if you link against iOS 9.

If your app uses location in the background (without showing the blue status bar) you have to set `allowsBackgroundLocationUpdates` to `YES` in addition to setting the background mode capability in Info.plist. Otherwise location updates are only delivered in foreground. The advantage is that you can now have location managers with background location updates and other location managers with only foreground location updates in the same app. You can also reset the value to `NO` to change the behavior.

The documentation is pretty clear about it:
 
> By default, this is NO for applications linked against iOS 9.0 or
> later, regardless of minimum deployment target.
> 
> With UIBackgroundModes set to include "location" in Info.plist, you
> must also set this property to YES at runtime whenever calling
> -startUpdatingLocation with the intent to continue in the background.
> 
> Setting this property to YES when UIBackgroundModes does not include
> "location" is a fatal error.
> 
> Resetting this property to NO is equivalent to omitting "location"
> from the UIBackgroundModes value.  Access to location is still
> permitted whenever the application is running (ie not suspended), and
> has sufficient authorization (ie it has WhenInUse authorization and is
> in use, or it has Always authorization).  However, the app will still
> be subject to the usual task suspension rules.
> 
> See -requestWhenInUseAuthorization and -requestAlwaysAuthorization for
> more details on possible authorization values.


  [6]: https://developer.apple.com/videos/wwdc/2015/?id=714
Set  Info.plist like：
 ![enter image description here][8]

  [8]:https://i.imgur.com/MAoKbUe.png

The syntax for the Info.plist configuration looks like this:

    <key>NSLocationAlwaysUsageDescription</key>
    <string>微博@iOS程序犭袁 请求后台定位权限</string>
    
    <key>UIBackgroundModes</key>
    <array>
        <string>location</string>
    </array>

Use like:

    _locationManager = [[CLLocationManager alloc] init];
    _locationManager.delegate = self;
    [_locationManager setDesiredAccuracy:kCLLocationAccuracyBest];
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8) {
        [_locationManager requestAlwaysAuthorization];
    }
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9) {
        _locationManager.allowsBackgroundLocationUpdates = YES;
    }
    [_locationManager startUpdatingLocation];




> 中文

## 1. Demo1_iOS9网络适配_改用更安全的HTTPS

TLS 1.2 协议 强制增强数据访问安全
系统 Foundation 框架下的相关网络请求，将不再默认使用 Http 等不安全的网络协议，而默认采用 TLS 1.2。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。
##2.Demo2_iOS9新特性_更灵活的后台定位

【iOS9在定位的问题上，有一个坏消息一个好消息】坏消息：如果不适配iOS9，就不能偷偷在后台定位（不带蓝条，见图）！好消息：将允许出现这种场景：同一App中的多个location manager：一些只能在前台定位，另一些可在后台定位，并可随时开启或者关闭特定location manager的后台定位。

如果没有请求后台定位的权限，也是可以在后台定位的，不过会带蓝条：
 ![enter image description here][9]
  [9]: https://i.imgur.com/UoqGHlG.png

如何偷偷在后台定位：请求后台定位权限：

	 // 1. 实例化定位管理器
    _locationManager = [[CLLocationManager alloc] init];
    // 2. 设置代理
    _locationManager.delegate = self;
    // 3. 定位精度
    [_locationManager setDesiredAccuracy:kCLLocationAccuracyBest];
    // 4.请求用户权限：分为：⓵只在前台开启定位⓶在后台也可定位，
    //注意：建议只请求⓵和⓶中的一个，如果两个权限都需要，只请求⓶即可，
    //⓵⓶这样的顺序，将导致bug：第一次启动程序后，系统将只请求⓵的权限，⓶的权限系统不会请求，只会在下一次启动应用时请求⓶
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8) {
        //[_locationManager requestWhenInUseAuthorization];//⓵只在前台开启定位
        [_locationManager requestAlwaysAuthorization];//⓶在后台也可定位
    }
    // 5.iOS9新特性：将允许出现这种场景：同一app中多个location manager：一些只能在前台定位，另一些可在后台定位（并可随时禁止其后台定位）。
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9) {
        _locationManager.allowsBackgroundLocationUpdates = YES;
    }
    // 6. 更新用户位置
    [_locationManager startUpdatingLocation];

但是如果照着这种方式尝试，而没有配置Info.plist，100%你的程序会崩溃掉，并报错：

> *** Assertion failure in -[CLLocationManager setAllowsBackgroundLocationUpdates:], /BuildRoot/Library/Caches/com.apple.xbs/Sources/CoreLocationFramework_Sim/CoreLocation-1808.1.5/Framework/CoreLocation/CLLocationManager.m:593


要将  Info.plist 配置如下：
 ![enter image description here][8]

  [8]:https://i.imgur.com/MAoKbUe.png

对应的 Info.plist 的XML源码是：

    <key>NSLocationAlwaysUsageDescription</key>
    <string>微博@iOS程序犭袁 请求后台定位权限</string>
    
    <key>UIBackgroundModes</key>
    <array>
        <string>location</string>
    </array>
##3.iOS9 Untrusted Enterprise Developer with no option to trust

Since iOS9 there is no option to trust an enterprise build. 
Before iOS9，it's very easy to use:if you touch the app,it'll apear this :

 ![enter image description here][10]
[10]http://i.stack.imgur.com/WwF76.png

You have to let the user  do like:
Go to Settings - General - Profiles - tap on your Profile - tap on Trust button.

![enter image description here][11]
[11]https://i.imgur.com/EUaNHzc.gif

##3.企业级分发

iOS9之前，企业级分发十分方便：点击App出现“信任按钮”，


![enter image description here][12]

[12]https://i.imgur.com/aSmM8bk.png

iOS9以后，企业级分发ipa包将遭到与Mac上dmg安装包一样的待遇：默认不能安装，也不再出现“信任按钮”

 ![enter image description here][10]

[10]http://i.stack.imgur.com/WwF76.png

必须让用户进行gif图中的设置（相关Demo：https://github.com/ChenYilong/iOS9AdaptationTips/ ）

 ![enter image description here][13]
[13]https://i.imgur.com/PXM235L.gif





