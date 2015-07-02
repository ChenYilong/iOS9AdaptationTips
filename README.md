# iOS9AdaptationTips



iOS9适配系列教程【中文在页面下方】
（ 更多iOS开发干货，欢迎关注  [微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/) ）
For more infomation ，welcome go to [my twitter](https://twitter.com/stevechen1010)

> English

## 1. Demo1_You'd better Convert HTTP to HTTPS 






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

##2.Demo2_iOS9 new feature  in CoreLocation :  background only when you need
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
##3.iOS9 Untrusted Enterprise Developer with no option to trust

Since iOS9 there is no option to trust an enterprise build. 
Before iOS9，it's very easy to use:if you touch the app,it'll apear this :

 ![enter image description here][10]

  [10]: http://i.stack.imgur.com/WwF76.png

Now:

 ![enter image description here][11]

  [11]: https://i.imgur.com/Skn9iXk.png
  
You have to let the user  do like:
Go to Settings - General - Profiles - tap on your Profile - tap on Trust button.

  ![enter image description here][12]

  [12]: https://i.imgur.com/AdGNYHe.gif


##4.bitcode optional 
After Xcode 7,bitcode option will be enabled by default,If your library was compiled without bitcode but the bitcode option is enabled in your project settings.You can




>  1. Update your library with bit code, or you'll get warnings like:

> (null): URGENT: all bitcode will be dropped because
> '/Users/myname/Library/Mobile
> Documents/com~apple~CloudDocs/foldername/appname/GoogleMobileAds.framework/GoogleMobileAds(GADSlot+AdEvents.o)'
> was built without bitcode. You must rebuild it with bitcode enabled
> (Xcode setting ENABLE_BITCODE), obtain an updated library from the
> vendor, or disable bitcode for this target. Note: This will be an
> error in the future.




>  2.  Say NO to Enable Bitcode in your target Build Settings 





>  ![enter image description here][15]



  [15]: https://i.imgur.com/OoOogUe.gif

and the Library Build Settings to remove the warnings

For more information,go to 
[documentation of bitcode in developer library][16]


  [16]: https://developer.apple.com/library/prerelease/watchos/documentation/IDEs/Conceptual/AppDistributionGuide/AppThinning/AppThinning.html#//apple_ref/doc/uid/TP40012582-CH35-SW2

,and WWDC 2015 Session 102: ["Platforms State of the Union"][17]


  [17]: https://developer.apple.com/videos/wwdc/2015/?id=102

 ![enter image description here][18]

  [18]: http://mobileforward.net/wp-content/uploads/2015/06/Screen-Shot-2015-06-12-at-6.57.54-PM-697x351.png
##5.Privacy and Your App【URL scheme changes】
iOS 9 has made a small change to the handling of URL scheme. You must whitelist the url's that your app will call out to using the `LSApplicationQueriesSchemes` key in your `Info.plist`. 

Please see post here: http://awkwardhare.com/post/121196006730/quick-take-on-ios-9-url-scheme-changes

The main conclusion is that:

> If you call the “canOpenURL” method on a URL that is not in your whitelist, it will return “NO”, even if there is an app installed that has registered to handle this scheme. A “This app is not allowed to query for scheme xxx” syslog entry will appear.

> If you call the “openURL” method on a URL that is not in your whitelist, it will fail silently. A “This app is not allowed to query for scheme xxx” syslog entry will appear.

The author also speculates that this is a bug with the OS and Apple will fix this in a subsequent release.

This is a new security feature of iOS 9. Watch [WWDC 2015 Session 703][19] for more information. 

 ![enter image description here][20]

  [20]: https://i.imgur.com/2HxWQqq.png
 
Any app built with SDK 9 needs to provide a `LSApplicationQueriesSchemes` entry in its plist file, declaring which schemes it attempts to query.

    <key>LSApplicationQueriesSchemes</key>
    <array>
     <string>urlscheme</string>
     <string>urlscheme2</string>
     <string>urlscheme3</string>
     <string>urlscheme4</string>
    </array> 

  [19]: https://developer.apple.com/videos/wwdc/2015/?id=703

##6. Support Slide Over and Split View of iOS 9

![enter image description here](http://cdn1.tnwcdn.com/wp-content/blogs.dir/1/files/2015/06/ew-.gif)
How to transition an an older project to support Slide Over and Split View of iOS 9？
You may find that all the demo projects was written by storyboard or xib,
but the older project's UI is written by code！

I would suggest switching to storyboards to make your life easy.

I would highly recommend you watch the following WWDC videos and then think about what exactly you need to do in order to support multi tasking.


 1. [Mysteries of Auto Layout, Part 1](https://developer.apple.com/videos/wwdc/2015/?id=218)

 2. [What's New in Storyboards](https://developer.apple.com/videos/wwdc/2015/?id=215)

 3. [Implementing UI Designs in Interface Builder](https://developer.apple.com/videos/wwdc/2015/?id=407)

 4. [Getting Started with Multitasking on iPad in iOS 9](https://developer.apple.com/videos/wwdc/2015/?id=205)

 5. [Optimizing Your App for Multitasking on iPad in iOS](https://developer.apple.com/videos/wwdc/2015/?id=212)





> 中文

## 1. Demo1_iOS9网络适配_改用更安全的HTTPS

TLS 1.2 协议 强制增强数据访问安全
系统 Foundation 框架下的相关网络请求，将不再默认使用 Http 等不安全的网络协议，而默认采用 TLS 1.2。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。

在讨论之前，跟往常一样，先说下iOS程序猿们最关心的问题：

###跟我有毛关系？需要我加班吗？！

首先咱们来看下业内对Apple这一做法的评论：
![enter image description here](https://i.imgur.com/XfBA67A.jpg)
这是某社交App上讨论，看来业内还是吐槽声和肯定声同在。

结论是：

> 跟你很有关系，加班吧，少年！

书归正传【严肃脸】，我们正式讨论下 WHAT，WHY，HOW：

 1. WHAT（什么是SSL/TLS？跟HTTP和HTTPS有什么关系）
 2. WHY（以前的HTTP不是也能用吗？为什么要用SSL/TLS，闲得慌？！Apple是不是又在反人类？）
 3. HOW（如何适配？---弱弱地问下：加班要多久？）

###WHAT（什么是SSL/TLS？跟HTTP和HTTPS有什么关系）

跟往常一样，先说结论：

> HTTP+SSL/TLS+TCP = HTTPS

TLS 是 SSL 新的别称。举个例子：

“TLS1.0”之于“SSL3.1”，犹“公元2015”之于“民国104”，或者是“一千克”之于“一公斤”，或者是“半斤”之于“八两”：称呼不同，但意思相同。

SSL 3.0版本之后的迭代版本被重新命名为TLS 1.0,

也就是说：

> TLS 1.0 ＝ SSL 3.1

所以他们是一个东西，我们平常也经常简单见到 “SSL/TLS” 这种说法。

我们常见的

那为什么标题是“使用HTTPS”而没有提及SSL和TLS什么事？
要理解这个，要看下一个公式：

> HTTP+SSL/TLS+TCP = HTTPS

![HTTP+SSL/TLS+TCP](http://www.zytrax.com/tech/survival/ssl-layers.gif)



打个比方：如果原来的 HTTP 是塑料水管，容易被戳破；那么如今新设计的 HTTPS 就像是在原有的塑料水管之外，再包一层金属水管。一来，原有的塑料水管照样运行；二来，用金属加固了之后，不容易被戳破。


目前，应用最广泛的是TLS 1.0，接下来是SSL 3.0。但是，主流浏览器都已经实现了TLS 1.2的支持。

常用的是下面这些：

 - SSL 2.0
 - SSL 3.0
 - TLS 1.0 (SSL 3.1)
 - TLS 1.1 (SSL 3.1)
 - TLS 1.2 (SSL 3.1)

> Apple让你的HTTP采用SSL/TLS协议，就是让你从HTTP转到HTTPS

###WHY（以前的HTTP不是也能用吗？为什么要用SSL/TLS，闲得慌？！Apple是不是又在反人类？）

> 不使用SSL/TLS的HTTP通信，就是不加密的通信！

所有信息明文传播，带来了三大风险：

 1. 窃听风险（eavesdropping）：第三方可以获知通信内容。
 2. 篡改风险（tampering）：第三方可以修改通信内容。
 3. 冒充风险（pretending）：第三方可以冒充他人身份参与通信。

SSL/TLS协议是为了解决这三大风险而设计的，希望达到：
 1. 所有信息都是加密传播，第三方无法窃听。
 2. 具有校验机制，一旦被篡改，通信双方会立刻发现。
 3. 配备身份证书，防止身份被冒充。

### HOW（如何适配？---弱弱地问下：加班要多久？）

正如文章开头所说：

> TLS 1.2 协议 强制增强数据访问安全 系统 Foundation 框架下的相关网络请求，将不再默认使用 Http 等不安全的网络协议，而默认采用 TLS 1.2。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。

方案一：立即让公司的服务端升级使用TLS 1.2

方案二：虽Apple不建议，但可通过在 Info.plist 中声明，倒退回不安全的网络请求依然能让App访问指定http，甚至任意的http，

具体做法见gif图，示例Demo见 [enter image description here](Demo1)


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

##3.企业级分发

iOS9之前，企业级分发十分方便：点击App出现“信任按钮”，


 ![enter image description here][13]

  [13]: https://i.imgur.com/aSmM8bk.png

iOS9以后，企业级分发ipa包将遭到与Mac上dmg安装包一样的待遇：默认不能安装，也不再出现“信任按钮”

 ![enter image description here][11]

  [11]: https://i.imgur.com/Skn9iXk.png

必须让用户进行gif图中的设置（相关Demo：https://github.com/ChenYilong/iOS9AdaptationTips/ ）


 ![enter image description here][14]

  [14]: https://i.imgur.com/PXM235L.gif


##4.Bitcode（通俗解释：在线版安卓ART模式）
未来Watch应用须包含Bitcode，iOS不强制，但Xcode7默认会开启Bitcode。

如何适配？方法一：更新library使包含Bitcode，否则会出现以下中的警告；

> (null): URGENT: all bitcode will be dropped because
> '/Users/myname/Library/Mobile
> Documents/com~apple~CloudDocs/foldername/appname/GoogleMobileAds.framework/GoogleMobileAds(GADSlot+AdEvents.o)'
> was built without bitcode. You must rebuild it with bitcode enabled
> (Xcode setting ENABLE_BITCODE), obtain an updated library from the
> vendor, or disable bitcode for this target. Note: This will be an
> error in the future.



方法二：关闭Bitcode，方法见下图

>  ![enter image description here][15]



  [15]: https://i.imgur.com/OoOogUe.gif

更多信息，请移步
[bitcode 苹果官方文档][16]


  [16]: https://developer.apple.com/library/prerelease/watchos/documentation/IDEs/Conceptual/AppDistributionGuide/AppThinning/AppThinning.html#//apple_ref/doc/uid/TP40012582-CH35-SW2

,和 WWDC 2015 Session 102: ["Platforms State of the Union"][17]


  [17]: https://developer.apple.com/videos/wwdc/2015/?id=102

 ![enter image description here][18]

  [18]: http://mobileforward.net/wp-content/uploads/2015/06/Screen-Shot-2015-06-12-at-6.57.54-PM-697x351.png
##5.URL scheme
在iOS9中，如果使用URL scheme必须在"Info.plist"中将你要在外部调用的URL scheme列为白名单，否则不能使用。key叫做LSApplicationQueriesSchemes ，键值内容是

	<key>LSApplicationQueriesSchemes</key>
	<array>
	 <string>urlscheme</string>
	 <string>urlscheme2</string>
	 <string>urlscheme3</string>
	 <string>urlscheme4</string>
	</array> 


推荐一篇博客: http://awkwardhare.com/post/121196006730/quick-take-on-ios-9-url-scheme-changes

其中最关键的是以下部分：

> If you call the “canOpenURL” method on a URL that is not in your whitelist, it will return “NO”, even if there is an app installed that has registered to handle this scheme. A “This app is not allowed to query for scheme xxx” syslog entry will appear.

> If you call the “openURL” method on a URL that is not in your whitelist, it will fail silently. A “This app is not allowed to query for scheme xxx” syslog entry will appear.

更多信息请移步：WWDC 2015 Session 703: "Privacy and Your App"  https://developer.apple.com/videos/wwdc/2015/?id=703 时间在30：18左右


 ![enter image description here][20]

  [20]: https://i.imgur.com/2HxWQqq.png
 

##6. iPad适配Slide Over 和 Split View

 ![enter image description here](http://cdn1.tnwcdn.com/wp-content/blogs.dir/1/files/2015/06/ew-.gif)
 
【iPad适配Slide Over 和 Split View】
若想适配multi tasking特性，唯一的建议：弃纯代码，改用storyboard、xib，纵观苹果WWDC所有Demo均是如此：


 1. [Mysteries of Auto Layout, Part 1](https://developer.apple.com/videos/wwdc/2015/?id=218)

 2. [What's New in Storyboards](https://developer.apple.com/videos/wwdc/2015/?id=215)

 3. [Implementing UI Designs in Interface Builder](https://developer.apple.com/videos/wwdc/2015/?id=407)

 4. [Getting Started with Multitasking on iPad in iOS 9](https://developer.apple.com/videos/wwdc/2015/?id=205)

 5. [Optimizing Your App for Multitasking on iPad in iOS](https://developer.apple.com/videos/wwdc/2015/?id=212)



