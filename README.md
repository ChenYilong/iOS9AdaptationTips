# iOS9AdaptationTips（iOS9开发学习交流群：523070828）



iOS9适配系列教程【中文在[页面下方](https://github.com/ChenYilong/iOS9AdaptationTips#1-demo1_ios9网络适配_ats改用更安全的https)】

（截至2015年9月26日共有10篇，后续还将持续更新。更多iOS开发干货，欢迎关注  [微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/) ）

#中文快速导航：


 1.  [iOS9网络适配_ATS：改用更安全的HTTPS（见Demo1）](https://github.com/ChenYilong/iOS9AdaptationTips#1-demo1_ios9网络适配_ats改用更安全的https) 
  1. [WHAT（什么是SSL/TLS？跟HTTP和HTTPS有什么关系）](https://github.com/ChenYilong/iOS9AdaptationTips#what什么是ssltls跟http和https有什么关系) 
  2.  [WHY（以前的HTTP不是也能用吗？为什么要用SSL/TLS？Apple是不是又在反人类？）](https://github.com/ChenYilong/iOS9AdaptationTips#why以前的http不是也能用吗为什么要用ssltlsapple是不是又在反人类) 
  3.  [HOW（如何适配？---弱弱地问下：加班要多久？）](https://github.com/ChenYilong/iOS9AdaptationTips#how如何适配---弱弱地问下加班要多久) 
     1.  [第1种情况：HTTPS Only （只有HTTPS，所有情况下都使用ATS）](https://github.com/ChenYilong/iOS9AdaptationTips#1https-only-只有https所有情况下都使用ats) 
     2.  [第2种情况：Mix & Match（混合）](https://github.com/ChenYilong/iOS9AdaptationTips#2mix--match混合) 
     3.  [第3种情况：Opt Out（禁用ATS）](https://github.com/ChenYilong/iOS9AdaptationTips#3-opt-out禁用ats) 
     4.  [第4种情况：Opt Out With Exceptions（除特殊情况外，都不使用ATS）](https://github.com/ChenYilong/iOS9AdaptationTips#4-opt-out-with-exceptions除特殊情况外都不使用ats) 
     4.  [Certificate Transparency](https://github.com/ChenYilong/iOS9AdaptationTips#certificate-transparency) 
  4.  [Q-A](https://github.com/ChenYilong/iOS9AdaptationTips#q-a) 
 2.  [iOS9新特性_更灵活的后台定位（见Demo2）](https://github.com/ChenYilong/iOS9AdaptationTips#2demo2_ios9新特性_更灵活的后台定位) 
 3.  [企业级分发](https://github.com/ChenYilong/iOS9AdaptationTips#3企业级分发) 
  1.  [iOS9以后，企业级分发ipa包将遭到与Mac上dmg安装包一样的待遇：默认不能安装，也不再出现“信任按钮”](https://github.com/ChenYilong/iOS9AdaptationTips#1-ios9以后企业级分发ipa包将遭到与mac上dmg安装包一样的待遇默认不能安装也不再出现信任按钮) 
  2.  [iOS9以后，企业分发时可能存在：下载的ipa包与网页两者的 bundle ID 无法匹配而导致下载失败的情况](https://github.com/ChenYilong/iOS9AdaptationTips#2-ios9以后企业分发时可能存在下载的ipa包与网页两者的-bundle-id-无法匹配而导致下载失败的情况) 
  3.   [iOS9以后，企业APP安装之后，在网络情况为Wi-Fi环境的时候，可能会出现无法验证应用的情况](https://github.com/ChenYilong/iOS9AdaptationTips#3-企业app安装之后在网络情况为wi-fi环境的时候可能会出现无法验证应用的情况出现以下提示) 
 4.  [Bitcode](https://github.com/ChenYilong/iOS9AdaptationTips#4bitcode) 
 5.  [iOS9 URL Scheme 适配_引入白名单概念（见Demo3）](https://github.com/ChenYilong/iOS9AdaptationTips#5demo3---ios9-url-scheme-适配_引入白名单概念) 
     1.   [常见 URL Scheme](https://github.com/ChenYilong/iOS9AdaptationTips#常见-url-scheme) 
     2.   [Q-A](https://github.com/ChenYilong/iOS9AdaptationTips#q-a-1) 
 6.  [ iPad适配Slide Over 和 Split View](https://github.com/ChenYilong/iOS9AdaptationTips#6-ipad适配slide-over-和-split-view) 
 7.  [字体间隙变大导致 UI 显示异常](https://github.com/ChenYilong/iOS9AdaptationTips#7字体间隙变大导致-ui-显示异常) 
 8.  [升级 Xcode7 后的崩溃与警告](https://github.com/ChenYilong/iOS9AdaptationTips#8升级-xcode7-后的崩溃与警告) 
  1.  [iOS9 下使用 Masonry 会引起崩溃的一种情况](https://github.com/ChenYilong/iOS9AdaptationTips#ios9-下使用-masonry-会引起崩溃的一种情况) 
  2.  [Xcode 升级后，旧的状态栏的样式设置方式会引起警告](https://github.com/ChenYilong/iOS9AdaptationTips#xcode-升级后旧的状态栏的样式设置方式会引起警告) 
        1.  [Demo4---navigationController状态栏样式新的设置方法](https://github.com/ChenYilong/iOS9AdaptationTips#demo4---navigationcontroller状态栏样式新的设置方法) 
  3.  [Xcode7 在 debug 状态下也生成 .dSYM 文件引起的警告](https://github.com/ChenYilong/iOS9AdaptationTips#xcode7-在-debug-状态下也生成-dsym-文件引起的警告) 
  4.  [Xcode7 无法使用 8.x 系统的设备调试，一运行就报错 there is an intenal API error](https://github.com/ChenYilong/iOS9AdaptationTips#xcode7-无法使用-8x-系统的设备调试一运行就报错-there-is-an-intenal-api-error) 
  5.  [使用了 HTML 的 iframe 元素可能导致无法从 Safari 跳转至 App](https://github.com/ChenYilong/iOS9AdaptationTips#使用了-html-的-iframe-元素可能导致无法从-safari-跳转至-app) 
  6.  [iOS9锁屏控制台会打印警告](https://github.com/ChenYilong/iOS9AdaptationTips#ios9锁屏控制台会打印警告)
  7. [Xcode7 上传应用时提示 ITMS-90535 Unable to publish iOS app with xxx SDK 的问题](http://stackoverflow.com/questions/32622899/itms-90535-unable-to-publish-ios-app-with-latest-google-signin-sdk)
  8.  [在didFinishLaunchingWithOptions结束后还没有设置window的rootViewController会导致崩溃](https://github.com/ChenYilong/iOS9AdaptationTips#在didfinishlaunchingwithoptions结束后还没有设置window的rootview
controller会导致崩溃) 
 9.  [Demo5、Demo6--- 搜索 API](https://github.com/ChenYilong/iOS9AdaptationTips#9demo5demo6----搜索-api)  
 10.   [iOS国际化问题：当前设备语言字符串返回有变化](https://github.com/ChenYilong/iOS9AdaptationTips#10ios国际化问题当前设备语言字符串返回有变化) 
 11.  [UITableView显示异常](https://github.com/ChenYilong/iOS9AdaptationTips#11uitableview显示异常) 
  1.  [代码创建的 tableView 无法隐藏 cell 分割线](https://github.com/ChenYilong/iOS9AdaptationTips#代码创建的-tableview-无法隐藏-cell-分割线) 
  2. [reloadData 刷新失效](https://github.com/ChenYilong/iOS9AdaptationTips#reloaddata-刷新失效)




# English⬇️⬇️

For more infomation ，welcome to follow [my twitter](https://twitter.com/stevechen1010)

## 1. Demo1_You'd better Convert HTTP to HTTPS 




How to deal with the SSL in iOS9，One solution is to  do like:
![enter image description here](https://github.com/ChenYilong/iOS9AdaptationTips/blob/master/Demo1_iOS9网络适配_改用更安全的HTTPS/微博%40iOS程序犭袁/http问题.gif)

As the  [Apple](https://developer.apple.com/library/prerelease/ios/releasenotes/General/WhatsNewIniOS/Articles/iOS9.html#//apple_ref/doc/uid/TP40016198-DontLinkElementID_13) say :


  ![enter image description here](https://i.imgur.com/eTgSHZY.png)
  
![enter image description here](https://i.imgur.com/Tc0fS6p.jpg)

![enter image description here](https://i.imgur.com/v2Tskwh.jpg)
  
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

If your server is support  TLSv1.2 ,but you also have to do what I say just now if you want to connect success in iOS9:

After some discussion with Apple Support, the issue is due to the self signed certificate.

ATS trusts only certificate signed by a well known CA, all others are rejected. As a consequence the only solution with a Self signed certificate is to set an exception with NSExceptionDomains.

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

Assuming two apps TestA and TestB. TestB wants to query if TestA is installed. "TestA" defines the following URL scheme in its info.plist file:

	<key>CFBundleURLTypes</key>
	<array>
		<dict>
			<key>CFBundleURLSchemes</key>
			<array>
				<string>testA</string>
			</array>
		</dict>
	</array>

The second app "TestB" tries to find out if "TestA" is installed by calling:

    [[UIApplication sharedApplication]
                        canOpenURL:[NSURL URLWithString:@"TestA://"]];

But this will normally return NO in iOS9 because "TestA" needs to be added to the LSApplicationQueriesSchemes entry in TestB's info.plist file. This is done by adding the following code to TestB's info.plist file:

    <key>LSApplicationQueriesSchemes</key>
    <array>
        <string>TestA</string>
    </array>

A working implementation can be found here:
https://github.com/gatzsche/LSApplicationQueriesSchemes-Working-Example

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

##License

Posted by [微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/) 

 [Creative Commons BY-NC-ND 3.0](http://creativecommons.org/licenses/by-nc-nd/3.0/deed.zh)

 



> 中文

## 1. Demo1_iOS9网络适配_ATS：改用更安全的HTTPS

[摘要]为了强制增强数据访问安全， iOS9 默认会把 <del>所有的http请求</del> 所有从`NSURLConnection` 、 `CFURL` 、 `NSURLSession`发出的 HTTP 请求，都改为 HTTPS 请求：iOS9.x-SDK编译时，默认会让所有从`NSURLConnection` 、 `CFURL` 、 `NSURLSession`发出的 HTTP 请求统一采用TLS 1.2 协议。因为 AFNetworking 现在的版本底层使用了 `NSURLConnection` ，众多App将被影响（基于iOS8.x-SDK的App不受影响）。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。而这一做法，官方文档称为ATS，全称为App Transport Security，是iOS9的一个新特性。

一个符合 ATS 要求的 HTTPS，应该满足如下条件：

 1. Transport Layer Security协议版本要求TLS1.2以上
 2. 服务的Ciphers配置要求支持Forward Secrecy等
 3. 证书签名算法符合ATS要求等

官方文档 [ ***App Transport Security Technote*** ](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240) 对ATS 的介绍：

![enter image description here](http://i58.tinypic.com/ajsf0j.jpg)


注：有童鞋反映：服务器已支持TLS 1.2 SSL ，但iOS9上还是不行，还要进行本文提出的适配操作。

那是因为：要注意 App Transport Security 要求 TLS 1.2，而且它要求站点使用支持forward secrecy协议的密码。证书也要求是符合ATS规格的，ATS只信任知名CA颁发的证书，小公司所使用的 self signed certificate，还是会被ATS拦截。。因此慎重检查与你的应用交互的服务器是不是符合ATS的要求非常重要。对此，建议使用下文中给出的NSExceptionDomains，并将你们公司的域名挂在下面。下文也会详细描述该问题。


官方文档 [ ***App Transport Security Technote*** ](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240) 对CA颁发的证书要求：

 > Certificates must be signed using a SHA256 or better signature hash algorithm, with either a 2048 bit or greater RSA key or a 256 bit or greater Elliptic-Curve (ECC) key.
Invalid certificates result in a hard failure and no connection


在讨论之前，跟往常一样，先说下iOS程序猿们最关心的问题：

###跟我有毛关系？需要我加班吗？！

首先咱们来看下业内对Apple这一做法的评论：

![enter image description here](https://i.imgur.com/Q17QDG0.png)

这是某社交App上讨论，看来业内还是吐槽声和肯定声同在。

结论是：

> 跟你很有关系，加班吧，少年！

书归正传【严肃脸】，我们正式讨论下 WHAT，WHY，HOW：

 1. WHAT（什么是SSL/TLS？跟HTTP和HTTPS有什么关系）
 2. WHY（以前的HTTP不是也能用吗？为什么要用SSL/TLS？！Apple是不是又在反人类？）
 3. HOW（如何适配？---弱弱地问下：加班要多久？）

###WHAT（什么是SSL/TLS？跟HTTP和HTTPS有什么关系）

什么是SSL/TLS？
SSL你一定知道，在此不做赘述。主要说下什么是TLS，还有跟HTTP和HTTPS有什么关系。

TLS 是 SSL 新的别称：

“TLS1.0”之于“SSL3.1”，犹“公元2015”之于“民国104”，“一千克”之于“一公斤”：称呼不同，意思相同。

SSL 3.0版本之后的迭代版本被重新命名为TLS 1.0：**TLS 1.0＝SSL 3.1**。所以我们平常也经常见到 “SSL/TLS” 这种说法。

目前，应用最广泛的是TLS 1.0，接下来是SSL 3.0。目前主流浏览器都已经实现了TLS 1.2的支持。

常用的有下面这些：

 - SSL 2.0
 - SSL 3.0
 - TLS 1.0 (SSL 3.1)
 - TLS 1.1 (SSL 3.1)
 - TLS 1.2 (SSL 3.1)

那为什么标题是“使用HTTPS”而没有提及SSL和TLS什么事？
“SSL/TLS”跟HTTP和HTTPS有什么关系？

要理解这个，要看下他们之间的关系：

> HTTP+SSL/TLS+TCP = HTTPS

![HTTP+SSL/TLS+TCP](http://www.zytrax.com/tech/survival/ssl-layers.gif)

或者

> HTTPS = “HTTP over SSL”

也就是说：

> Apple让你的HTTP采用SSL/TLS协议，就是让你从HTTP转到HTTPS。而这一做法，官方文档称为ATS，全称为App Transport Security。

###WHY（以前的HTTP不是也能用吗？为什么要用SSL/TLS？Apple是不是又在反人类？）

> 不使用SSL/TLS的HTTP通信，就是不加密的通信！

 不使用SSL/TLS的HTTP通信，所有信息明文传播，带来了三大风险：

 1. 窃听风险（eavesdropping）：第三方可以获知通信内容。
 2. 篡改风险（tampering）：第三方可以修改通信内容。
 3. 冒充风险（pretending）：第三方可以冒充他人身份参与通信。

SSL/TLS协议是为了解决这三大风险而设计的，希望达到：
 1. 所有信息都是加密传播，第三方无法窃听。
 2. 具有校验机制，一旦被篡改，通信双方会立刻发现。
 3. 配备身份证书，防止身份被冒充。

SSL/TLS的作用，打个比方来讲：

如果原来的 HTTP 是塑料水管，容易被戳破；那么如今新设计的 HTTPS 就像是在原有的塑料水管之外，再包一层金属水管（SSL/TLS协议）。一来，原有的塑料水管照样运行；二来，用金属加固了之后，不容易被戳破。





### HOW（如何适配？---弱弱地问下：加班要多久？）

正如文章开头所说：

> TLS 1.2 协议 强制增强数据访问安全 系统 Foundation 框架下的“相关网络请求”将不再默认使用 HTTP 等不安全的网络协议，而默认采用 TLS 1.2。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。

总之：

> 要么咱们iOS程序猿加班，要么后台加班：


方案一：立即让公司的服务端升级使用TLS 1.2，以解析相关数据。

方案二：虽Apple不建议，但可通过在 Info.plist 中声明，倒退回不安全的网络请求依然能让App访问指定http，甚至任意的http，具体做法见gif图，示例Demo见 [Demo1](https://github.com/ChenYilong/iOS9AdaptationTips)

![enter image description here](https://github.com/ChenYilong/iOS9AdaptationTips/blob/master/Demo1_iOS9网络适配_改用更安全的HTTPS/微博%40iOS程序犭袁/http问题.gif)

这也是官方文档和WWDC给出的解决方案：

 1.   [Apple官方文档](https://developer.apple.com/library/prerelease/ios/releasenotes/General/WhatsNewIniOS/Articles/iOS9.html#//apple_ref/doc/uid/TP40016198-DontLinkElementID_13)  ![enter image description here](https://i.imgur.com/eTgSHZY.png)


 2. [WWDC Session： "Networking with NSURLSession" session（ 【WWDC 2015 session 703, “Privacy and Your App” O网页链接 】, 时间在30:18左右）](https://developer.apple.com/videos/wwdc/2015/?id=703)





 ![enter image description here](https://i.imgur.com/Tc0fS6p.jpg)

 ![enter image description here](https://i.imgur.com/v2Tskwh.jpg)
  
  ![enter image description here](https://cdn-images-1.medium.com/max/800/1*9-VeRXU5SAI6lLZeWLI0hQ.png)


即使你的应用使用的是：你没有权限控制的CDN (Content Delivery Network)，而且它不支持HTTPS！

也别担心，Apple都替你考虑好了：

 ![enter image description here](http://i61.tinypic.com/ae9tgj.jpg)
 
 正如你在上图中看到的：苹果官方提供了一些可选配置项来决定是否开启ATS模式，也就是可以选择开启或者不开启。

 开发者可以针对某些确定的URL不使用ATS，这需要在工程中的info.plist中标记NSExceptionDomains。在NSExceptionDomains字典中，可以显式的指定一些不使用ATS的URL。这些你可以使用的例子可以是:

  - NSIncludesSubdomains

  - NSExceptionAllowInsecureHTTPLoads

  - NSExceptionRequiresForwardSecrecy

  - NSExceptionMinimumTLSVersion

  - NSThirdPartyExceptionAllowsInsecureHTTPLoads

  - NSThirdPartyExceptionMinimumTLSVersion

  - NSThirdPartyExceptionRequiresForwardSecrecy



这些关键字使我们可以更加细致的设置针对不使用ATS的域名情况下禁用ATS或者一些特殊的ATS选项。

你可能注意到一些关键字像是使用了一些其他关键字中的词但是在前面加上了"ThirdParty"字样，比如列表里最后三个：

- NSThirdPartyExceptionAllowsInsecureHTTPLoads

- NSThirdPartyExceptionMinimumTLSVersion

- NSThirdPartyExceptionRequiresForwardSecrecy

在功能上，这些关键字与不含有"ThirdParty"的关键字有同样的效果。而且实际运行中所调用的代码将会完全忽略是否使用"ThirdParty"关键字。你应该使用适用于你的场景的关键字而不必过多考虑这些。

关于App Transport Security，每个应用都属于4个大类当中的一类。我们来看看每一个大类都是怎样影响应用的。


|--| 分类名|解释|
-------------|-------------|-------------
1.|HTTPS Only （只有HTTPS，所有情况下都使用ATS）|如果你的应用只基于支持HTTPS的服务器，你的应用不需要做任何改变。但是，注意App Transport Security要求TLS 1.2，而且它要求站点使用支持forward secrecy协议的密码。证书也要求是符合ATS规格的。因此慎重检查与你的应用交互的服务器是不是符合ATS的要求。
2.|Mix & Match（混合）|如果你的服务器不符合ATS要求，你需要在你的应用的 Info.plist 文件中说明哪些地址是不符合ATS要求的。
3.|Opt Out（禁用ATS）|如果你在创建一个网页浏览器，因为你不能确定用户将要访问哪个网页，也就不可能指明这些网页是否支持ATS要求且在HTTPS上传输。在这种情况下，只能配置为禁用ATS。
4.|Opt Out With Exceptions（除特殊情况外，都不使用ATS）|如果想禁用ATS的同时又想定义一些例外。这个应用场景是当你的应用需要从很多不符合ATS要求的服务器上取数据，但是也要与一个你可控的API(符合ATS要求)交互。在这种情况下，需要在应用的 Info.plist 文件中配置为允许所有请求，但是你也指定了一个或多个例外来表明哪些请求是必须符合ATS的要求。

下面分别做一下介绍：

####1.HTTPS Only （只有HTTPS，所有情况下都使用ATS）
如果你的应用只基于支持HTTPS的服务器，那么你太幸运了。你的应用不需要做任何改变。

唯一需要做的事情就是使用  `NSURLSession` 。如果你的开发目标是iOS 9或者 OS X EI Capitan之后，ATS 的最佳实践将会应用到所有基于 `NSURLSession` 的网络。

但也有人遇到过这样的疑惑：服务器已支持TLS 1.2 SSL ，但iOS9上还是不行，还要进行本文提出的适配操作。


那是因为：要注意 App Transport Security 要求 TLS 1.2，而且它要求站点使用支持forward secrecy协议的密码。证书也要求是符合ATS规格的，ATS只信任知名CA颁发的证书，小公司所使用的 self signed certificate，还是会被ATS拦截。因此慎重检查与你的应用交互的服务器是不是符合ATS的要求非常重要。对此，建议使用下文中给出的NSExceptionDomains，并将你们公司的域名挂在下面。

官方文档 [ ***App Transport Security Technote*** ](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240) 对CA颁发的证书要求：

 > Certificates must be signed using a SHA256 or better signature hash algorithm, with either a 2048 bit or greater RSA key or a 256 bit or greater Elliptic-Curve (ECC) key.
Invalid certificates result in a hard failure and no connection



####2.Mix & Match（混合）	

如果你的服务器不符合ATS要求。

比如当你遇到以下三个不符合 ATS 要求的服务器的域名时：

 1. api.insecuredomain.com
 2. cdn.domain.com
 3. thatotherdomain.com

你可以分别设置如下：        
        
 1. api.insecuredomain.com

 Info.plist 配置中的XML源码如下所示:


 ```XML
    <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSExceptionDomains</key>
        <dict>
            <key>api.insecuredomain.com</key>
            <dict>
                
                <!--允许App进行不安全的HTTP请求-->
                <key>NSExceptionAllowsInsecureHTTPLoads</key>
                <true/>
                
                <!--适用于这个特定域名下的所有子域-->
                <key>NSIncludesSubdomains</key>
                <true/>
            </dict>
        </dict>
    </dict>
 ```


 在 plist 文件里显示如下：


 ![enter image description here](http://i59.tinypic.com/fxtk0j.jpg)

 我们定义的第一个“例外”（Exception）告诉ATS当与这个子域交互的时候撤销了必须使用HTTPS的要求。注意这个仅仅针对在“例外”（Exception）中声明了的子域。非常重要的一点是要理解NSExceptionAllowsInsecureHTTPLoads关键字并不仅仅只是与使用HTTPS相关。这个“例外”（Exception）指明了对于那个域名，所有的App Transport Security的要求都被撤销了。



 2. cdn.domain.com
 Info.plist 配置中的XML源码如下所示:


 ```XML
	<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSExceptionDomains</key>
		<dict>
			<key>cdn.somedomain.com</key>
			<dict>
				<key>NSThirdPartyExceptionMinimumTLSVersion</key>
				<string>TLSv1.1</string>
			</dict>
		</dict>
	</dict>
 ```


 在 plist 文件里显示如下：

  ![enter image description here](http://i58.tinypic.com/29atm5k.jpg)

 很可能你的应用是与一个支持HTTPS传输数据的服务器交互，但是并没有使用TLS 1.2或更高。在这种情况下，你定义一个“例外”（Exception），它指明应该使用的最小的TLS的版本。这比完全撤销那个域名的App Transport Security要更好更安全。

 3. thatotherdomain.com

 Info.plist 配置中的XML源码如下所示:

 ```XML
       <key>NSAppTransportSecurity</key>
        <dict>
            <key>NSExceptionDomains</key>
            <dict>
                <key>thatotherdomain.com</key>
                <dict>
                    <!--适用于这个特定域名下的所有子域-->
                    <key>NSIncludesSubdomains</key>
                    <true/>
                    <!--扩展可接受的密码列表：这个域名可以使用不支持 forward secrecy 协议的密码-->
                    <key>NSExceptionRequiresForwardSecrecy</key>
                    <false/>
                    <!--允许App进行不安全的HTTP请求-->
                    <key>NSExceptionAllowsInsecureHTTPLoads</key>
                    <true/>
                    <!--在这里声明所支持的 TLS 最低版本-->
                    <key>NSExceptionMinimumTLSVersion</key>
                    <string>TLSv1.1</string>
                </dict>
            </dict>
        </dict>
 ```

 在 plist 文件里显示如下：


 ![enter image description here](http://i61.tinypic.com/w6xn43.jpg)

 `NSIncludesSubdomains` 关键字告诉 App Transport Security 这个“例外”（Exception）适用于这个特定域名的所有子域。这个“例外”（Exception）还进一步通过扩展可接受的密码列表来定义这个域名可以使用不支持forward secrecy( `NSExceptionRequiresForwardSecrecy` )  协议的密码。想了解更多关于forward secrecy的信息，推荐去看官方文档  [ ***Apple's technote*** ](https://developer.apple.com/library/prerelease/mac/technotes/App-Transport-Security-Technote/index.html) 。

如果你的App中同时用到了这三个域名，那么应该是这样：

 ```XML
     <key>NSAppTransportSecurity</key>
        <dict>
            <key>NSExceptionDomains</key>
            <dict>
                <key>api.insecuredomain.com</key>
                <dict>
                    <key>NSExceptionAllowsInsecureHTTPLoads</key>
                    <false/>
                </dict>
                <key>cdn.somedomain.com</key>
                <dict>
                    <key>NSThirdPartyExceptionMinimumTLSVersion</key>
                    <string>TLSv1.1</string>
                </dict>
                <key>thatotherdomain.com</key>
                <dict>
                    <key>NSIncludesSubdomains</key>
                    <true/>
                    <key>NSExceptionRequiresForwardSecrecy</key>
                    <false/>
                </dict>
            </dict>
        </dict>
 ```

![enter image description here](http://i61.tinypic.com/13ynggk.jpg)

#### 3. Opt Out（禁用ATS）
上面是比较严谨的做法，指定了能访问哪些特定的HTTP。当然也有暴力的做法：
彻底倒退回不安全的HTTP网络请求，能任意进行HTTP请求，比如你在开发一款浏览器App，或者你想偷懒，或者后台想偷懒，或者公司不给你升级服务器。。。

你可以在Info.plist 配置中改用下面的XML源码：


 ```XML
    <key>NSAppTransportSecurity</key>
    <dict>
        <!--彻底倒退回不安全的HTTP网络请求，能任意进行HTTP请求 (不建议这样做)-->
	    <key>NSAllowsArbitraryLoads</key>
	    <true/>
    </dict>
 ```


在 plist 文件里显示如下：

![enter image description here](http://i57.tinypic.com/9uq2c7.jpg)

#### 4. Opt Out With Exceptions（除特殊情况外，都不使用ATS）

上面已经介绍了三种情景，还有一种可能你也会遇到：

当你禁用ATS的同时又想定义一些“例外”（Exception）。这个应用场景是当你的应用需要从很多不符合ATS要求的服务器上取数据，但是也要与一个你可控的API(符合ATS要求)交互。在这种情况下，在应用的Info.plist文件中配置为允许所有请求，但是你也指定了一个或多个“例外”（Exception）来表明哪些地址是必须符合 App Transport Security 要求的。下面是Info.plist文件应该会有的内容：


 ```XML
<key>NSAppTransportSecurity</key>
        <dict>
            <key>NSAllowsArbitraryLoads</key>
            <true/>
            <key>NSExceptionDomains</key>
            <dict>
                <key>api.tutsplus.com</key>
                <dict>
                    <key>NSExceptionAllowsInsecureHTTPLoads</key>
                    <false/>
                </dict>
            </dict>
        </dict>
 ```

 在 plist 文件里显示如下：

![enter image description here](http://i62.tinypic.com/de1rw9.jpg)


 <p><del>【注：以上在Info.plist配置中的做法已经验证可行，但目前Apple的prerelease版本的官方文档并未提及Info.plist中配置的代码，我将密切关注官方文档，如有提及，再来更新[本文](https://github.com/ChenYilong/iOS9AdaptationTips) .你若发现官方文档有提及了，也可在[微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/)通知下我。】（官方文档已经有阐述）</del></p>

####Certificate Transparency

虽然ATS大多数安全特性都是默认可用的，Certificate Transparency 是必须设置的。如果你有支持Certificate Transparency的证书，你可以检查NSRequiresCertificateTransparency关键字来使用Certificate Transparency。再次强调，如果你的证书不支持Certificate Transparency，此项需要设置为不可用。

如果需要调试一些由于采用了ATS而产生的问题，需要设置CFNETWORK_DIAGNOSTICS为1，这样就会打印出包含被访问的URL和ATS错误在内的NSURLSession错误信息。要确保处理了遇到的所有的错误消息，这样才能使ATS易于提高可靠性和扩展性。

####Q-A

Q：我用xcode7编译的app，如果不在plist里面加关键字说明，ios9下不能进行网络请求，因为我们服务器并不支持 TLS 1.2 ，我要是直接下载app store上的，什么也没有做，也是能正常网络请求。

A：本文中所罗列的新特性，多数情况下指的是 iOS9.X-SDK 新特性，AppStore 的版本是基于 iOS8.X-SDK或 iOS7.X-SDK，所以并不受 iOS9新特性约束。也就是说：**Xcode7给iOS8打设备包可以请求到网络，Xcode7给iOS9设备打的包请求不到网络，Xcode7和iOS9缺一不可，才需要网络适配ATS。**


那么，如何确认自己项目所使用的 SDK？在Targets->Build Setting-->Architectures


![enter image description here](http://i58.tinypic.com/amsa9u.jpg)

Q：服务器已支持TLS 1.2 SSL ，但iOS9上还是不行，还要进行本文提出的适配操作。


A：那是因为：要注意 App Transport Security 要求 TLS 1.2，而且它要求站点使用支持forward secrecy协议的密码。证书也要求是符合ATS规格的，ATS只信任知名CA颁发的证书，小公司所使用的 self signed certificate，还是会被ATS拦截。。因此慎重检查与你的应用交互的服务器是不是符合ATS的要求非常重要。对此，建议使用下文中给出的NSExceptionDomains，并将你们公司的域名挂在下面。


官方文档 [ ***App Transport Security Technote*** ](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240) 对CA颁发的证书要求：

 > Certificates must be signed using a SHA256 or better signature hash algorithm, with either a 2048 bit or greater RSA key or a 256 bit or greater Elliptic-Curve (ECC) key.
Invalid certificates result in a hard failure and no connection

Q：我使用的是第三方的网络框架，比如 AFNetworking 、ASIHTTPRequest、CFSocket 等，这个有影响没有？

A： AFNetworking 有影响，其它没影响。

 ATS 是只针对 `NSURLConnection` 、 `CFURL` 、 `NSURLSession` ，如果底层涉及到这三个类就会有影响。

现在的 AFNetworking 的 AFHTTPRequestOperationManager 实现是使用的 `NSURLConnection` 。

但 AFNetworking 也有更新计划，移除 `NSURLConnection` 相关API，迁移到 AFHTTPSessionManager ，但还未执行，详情见：[https://github.com/AFNetworking/AFNetworking/issues/2806](https://github.com/AFNetworking/AFNetworking/issues/2806)。


Q：试了一下禁用 ATS 的方法 但是还是无法联网 仍然提示要使用https?


 > App Transport Security has blocked a cleartext HTTP (http://) resource load since it is insecure. Temporary exceptions can be configured via your app&#039;s Info.plist file.
</p>The resource could not be loaded because the App Transport Security policy requires the use of a secure connection.


A：遇到这类问题，90%是出现在“一个 Project 多 Target ”的情况下，所以
请确保你修改的，确实是你的 Target 所属的 Info.plist ！

如何确认？请前往这里，确认你 Target 所属的 Info.plist 究竟是哪个：

Project -> Your Target -> Build Settings -> Info.plist File

![enter image description here](http://i60.tinypic.com/sbrfrl.jpg)

或者更直截了当一点，直接修改：

Project -> Your Target —>info－> Custom iOS target properties－> 添加禁用 ATS 的属性

![enter image description here](http://i60.tinypic.com/zvbt7b.jpg)

还有一种可能性是：禁用 ATS 的代码粘贴进 plist 时，位置不对，可以尝试放在 diwuhang


Q：我的项目是“一个 Project 多 Target ”，按照本文禁用 ATS 的方法，是不是每个 Info.plist 都要修改？

A：不需要，用到哪个 Target 修改哪个的 Info.plist ，Target 是独立的，不受其他 Target 的影响，也不会影响其他 Target。

Q：如何检测我们公司 HTTPS 是否符合 ATS 的要求？

A：
如果你的 App 的服务也在升级以适配ATS要求，可以使用如下的方式进行校验：

在OS X EI Capitan系统的终端中通过nscurl命令来诊断检查你的HTTPS服务配置是否满足Apple的ATS要求:

 ```Objective-C
 $ nscurl --verbose --ats-diagnostics https://<your_server_domain>
 ```

当然，你也可以让公司服务端的同事参考Apple提供官方指南App Transport Security Technote进行服务的升级配置以满足ATS的要求：

一个符合 ATS 要求的 HTTPS，应该满足如下条件：

 1. Transport Layer Security协议版本要求TLS1.2以上
 2. 服务的Ciphers配置要求支持Forward Secrecy等
 3. 证书签名算法符合ATS要求等


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


这个问题，有两种方式可以解决：

第一种：

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

第二种：

在对应 target 的 Capabilities -> Background Modes -> 开启 Location Updates 

![enter image description here](http://cdn2.raywenderlich.com/wp-content/uploads/2014/12/background_modes.png)



##3.企业级分发

有两处变化：

 1. iOS9以后，企业级分发ipa包将遭到与Mac上dmg安装包一样的待遇：默认不能安装，也不再出现“信任按钮”
 2. iOS9以后，企业分发时可能存在：下载的ipa包与网页两者的 bundle ID 无法匹配而导致下载失败的情况


###  1. iOS9以后，企业级分发ipa包将遭到与Mac上dmg安装包一样的待遇：默认不能安装，也不再出现“信任按钮”

iOS9之前，企业级分发十分方便：点击App出现“信任按钮”，


 ![enter image description here][13]

  [13]: https://i.imgur.com/aSmM8bk.png

iOS9以后，企业级分发ipa包将遭到与Mac上dmg安装包一样的待遇：默认不能安装，也不再出现“信任按钮”

 ![enter image description here][11]

  [11]: http://i58.tinypic.com/2zecm83.jpg

必须让用户进行gif图中的设置：


 ![enter image description here][14]

  [14]: https://i.imgur.com/PXM235L.gif

### 2. iOS9以后，企业分发时可能存在：下载的ipa包与网页两者的 bundle ID 无法匹配而导致下载失败的情况

iOS9升级后众多企业分发的 app 已经出现了不能安装的情况，而iOS8或更早的系统不受影响。那是因为从iOS9以后，系统会在 ipa 包下载完之后，拿ipa包中的 bundle ID 与网页中的 plist 文件中的 bundle ID 进行比对，不一致不允许安装。

错误提示如下：

![enter image description here](http://i57.tinypic.com/28jckus.jpg)

网页中的 plist 文件中的 bundle ID 的作用可参考 [《iOS:苹果企业证书通过网页分发安装app》](http://blog.sina.com.cn/s/blog_6afb7d800101fa16.html) 。

正如这篇文章提到的，“网页中的 plist 文件”是习惯的叫法，也有人称作“manifest文件”，比如 [这篇文章](http://gknops.github.io/adHocGenerate/)。


而iOS9之前，苹果不会检查这一项，因此iOS9之前可以安装。

导致这一错误的原因除了粗心，还有开发者是故意设置不一致，据开发者说：

 > 当初服务器 plist 的 bundle id 上故意做成成不一致。是为了解决一些人安装不上的问题。


详情可参考： [《升级到ios 9，企业版发布现在无法安装成功了，有人遇到了这种问题吗？》](http://www.cocoachina.com/bbs/read.php?tid-324230-fpage-2-page-1.html) 




如何知道是因为 bundle id 不一致造成的无法安装？

通过查看设备上的日志信息：有一个 itunesstored 进程提示安装信息：

      itunesstored →  <Warning>: [Download]: Download task did finish: 8 for download: 2325728577585828282
      itunesstored →  <Warning>: [ApplicationWorkspace] Installing download: 2325728577585828282 with step(s): Install
      itunesstored →  <Warning>: [ApplicationWorkspace]: Installing software package with bundleID: com.***.***: bundleVersion: 1.01 path: /var/mobile/Media/Downloads/2325728577585828282/-1925357977307433048
      itunesstored →  <Warning>: BundleValidator: Failed bundleIdentifier: com.***.**** does not match expected bundleIdentifier: com.***.*********
      itunesstored →  <Warning>: [ApplicationWorkspace]: Bundle validated for bundleIdentifier: com.****.******success: 0
      itunesstored →  <Warning>: LaunchServices: Uninstalling placeholder for app <LSApplicationProxy: 0x12677be70> com.****.*******(Placeholder) <file:///private/var/mobile/Containers/Bundle/Application/B62D8EA3-2052-4393-8A7E-3FD27228BFC2/2325728577585828282.app>
      itunesstored →  <Warning>: LaunchServices: Uninstalling app <LSApplicationProxy: 0x12677be70> com.****.*****(Placeholder) <file:///private/var/mobile/Containers/Bundle/Application/B62D8EA3-2052-4393-8A7E-3FD27228BFC2/2325728577585828282.app>

其中的这一句很重要：

     itunesstored →  <Warning>: BundleValidator: Failed bundleIdentifier: com.***.**** does not match expected bundleIdentifier: com.***.*********

经过核对，果然是.ipa文件中真实的Bundle ID和manifest文件中配置的信息不匹配，然后测试发现：

> iOS 9是校验bundle-identifier值的，而iOS 9以下版本是不校验，一旦iOS 9发现bundle-identifier不匹配，即使下载成功了，也会 Uninstall(日志中提示的)app的。


适配方法：

 1. 两者的 bundle id 修改一致

 一旦出现iOS9能够安装企业版本APP，iOS9以下版本不能安装，一定先查看安装日志，然后核对每个参数配置。

 manifest文件的参考配置。

 ```XML
 <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN"
"http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
   <!-- array of downloads. -->
   <key>items</key>
   <array>
       <dict>
           <!-- an array of assets to download -->
           <key>assets</key>
           <array>
               <!-- software-package: the ipa to install. -->
               <dict>
                   <!-- required.  the asset kind. -->
                   <key>kind</key>
                   <string>software-package</string>
                   <!-- optional.  md5 every n bytes.  -->
                   <!-- will restart a chunk if md5 fails. -->
                   <key>md5-size</key>
                   <integer>10485760</integer>
                   <!-- optional.  array of md5 hashes -->
                   <key>md5s</key>
                   <array>
                       <string>41fa64bb7a7cae5a46bfb45821ac8bba</string>
                       <string>51fa64bb7a7cae5a46bfb45821ac8bba</string>
                   </array>
                   <!-- required.  the URL of the file to download. -->
                   <key>url</key>
                   <string>http://www.example.com/apps/foo.ipa</string>
               </dict>
               <!-- display-image: the icon to display during download. -->
               <dict>
                   <key>kind</key>
                   <string>display-image</string>
                   <!-- optional. icon needs shine effect applied. -->
                   <key>needs-shine</key>
                   <true/>
                   <key>url</key>
                   <string>http://www.example.com/image.57×57.png</string>
               </dict>
               <!-- full-size-image: the large 512×512 icon used by iTunes. -->
               <dict>
                   <key>kind</key>
                   <string>full-size-image</string>
                   <!-- optional.  one md5 hash for the entire file. -->
                   <key>md5</key>
                   <string>61fa64bb7a7cae5a46bfb45821ac8bba</string>
                   <key>needs-shine</key>
                   <true/>
                   <key>url</key>
                   <string>http://www.example.com/image.512×512.jpg</string>
               </dict>
           </array><key>metadata</key>
           <dict>
               <!-- required -->
               <key>bundle-identifier</key>
               <string>com.example.fooapp</string>
               <!-- optional (software only) -->
               <key>bundle-version</key>
               <string>1.0</string>
               <!-- required.  the download kind. -->
               <key>kind</key>
               <string>software</string>
               <!-- optional. displayed during download; -->
               <!-- typically company name -->
               <key>subtitle</key>
               <string>Apple</string>
               <!-- required.  the title to display during the download. -->
               <key>title</key>
               <string>Example Corporate App</string>
           </dict>
       </dict>
   </array>
</dict>
</plist>
 ```


 2. 使用fir.im等第三方分发平台：上述“ bundle id 不一致导致下载失败”这种情况只会出现在企业自己搭建网页分发的情形下，事实证明第三方的分发平台更加专业，已经很好地规避了该情况的发生。

### 3. 企业APP安装之后，在网络情况为Wi-Fi环境的时候，可能会出现无法验证应用的情况。出现以下提示：

**无法验证"**** Co.,Ltd"应用，需要网络连接以在这台iPhone上验证"**** Co.,Ltd"应用。接入互联网并重试。**

![](http://i63.tinypic.com/10ho85w.jpg)  
![](http://i66.tinypic.com/30ucruo.jpg)  
![](http://i66.tinypic.com/w14qi1.jpg)

而此时，Wi-Fi网络是接入互联网的。如果多次验证不通过的话，我们需要切换到非Wi-Fi网络环境下才能解决这个问题。

### Q-A

Q：企业分发，企业版证书在iOS9上安装应用报 ` Ignore manifest download, already have bundleID: com.mycom.MyApp`  只有我的手机无法安装，别人 iOS9 都可以安装

A：这并非 iOS9的问题，iOS8及以前的系统也会出现，和缓存有关系，请尝试关机重启手机，然后就可以安装了。

 
 Q：为什么用微信扫描二维码不能直接下载？
 
 A：部分市场支持直接扫描二维码下载（如蒲公英，fir.im等）,但是用微信扫描二维码不能直接。因为安装app所在页面必须要符合苹果`itms-services`协议，在不符合该协议的页面点击安装会没有反应。比如使用微信、QQ扫描点击安装会没有反应。

此时需要在微信或QQ安装页面点击右上角按钮，在弹出框里找到使用Safari浏览器打开选项，点击跳转到系统浏览器Safari里后再点击“安装”按钮进行安装。

部分第三分浏览器支持`itms-services`协议，可以直接点击安装。

## 4.Bitcode

【前言】未来， Watch 应用必须包含 bitcode ，iOS不强制，Mac OS不支持。
但最坑的一点是： Xcode7 及以上版本会默认开启 bitcode 。

什么是 bitcode ？

通俗解释：在线版安卓ART模式。

Apple 官方文档--[ ***App Distribution Guide – App Thinning (iOS, watchOS)*** ](https://developer.apple.com/library/prerelease/ios/documentation/IDEs/Conceptual/AppDistributionGuide/AppThinning/AppThinning.html#//apple_ref/doc/uid/TP40012582-CH35)是这样定义的：

> Bitcode is an intermediate representation of a compiled program. Apps you upload to iTunes Connect that contain bitcode will be compiled and linked on the App Store. Including bitcode will allow Apple to re-optimize your app binary in the future without the need to submit a new version of your app to the store.

翻译过来就是：

>  bitcode 是被编译程序的一种中间形式的代码。包含 bitcode 配置的程序将会在 App Store 上被编译和链接。 bitcode 允许苹果在后期重新优化我们程序的二进制文件，而不需要我们重新提交一个新的版本到 App Store 上。


在 Xcode简介--- [ ***What’s New in Xcode-New Features in Xcode 7*** ](https://developer.apple.com/library/prerelease/ios/documentation/DeveloperTools/Conceptual/WhatsNewXcode/Articles/xcode_7_0.html)中这样描述：


 > Bitcode. When you archive for submission to the App Store, Xcode will compile your app into an intermediate representation. The App Store will then compile the bitcode down into the 64 or 32 bit executables as necessary.

也就是

 > 当我们提交程序到 App Store上时， Xcode 会将程序编译为一个中间表现形式( bitcode )。然后 App store 会再将这个 bitcode 编译为可执行的64位或32位程序。


再看看这两段描述都是放在App Thinning(App瘦身)一节中，可以看出其与包的优化有关了。

打个比方，没有 bitcode  的 AppStore 里所提供的 App，类似在新华书店里卖捆绑销售的《四大名著丛书--精装版》，要买只能全买走，有了 bitcode 就好比这套四大名著每本都可以单卖，顾客就能按需购买。我们开发者在这个过程中扮演的角色是图书出版商的角色，应该照顾那些没钱一次买四本的顾客。（不要做不珍惜用户流量和存储空间的奸商。。）

那为什么第三方的 SDK 不支持 bitcode，我的 app 也就不能支持？打个比方，《四大名著丛书》只要有一本是可以单卖的，那么你很难再卖捆绑销售款的《四大名著丛书》了，所以干脆全都可以单卖，这大概就是 Apple 的逻辑。

 App Thinning 官方文档解释如下：


 > The App Store and operating system optimize the installation of iOS and watchOS apps by tailoring app delivery to the capabilities of the user’s particular device, with minimal footprint. This optimization, called app thinning, lets you create apps that use the most device features, occupy minimum disk space, and accommodate future updates that can be applied by Apple. Faster downloads and more space for other apps and content provides a better user experience.


开发者都知道，当前 iOS App 的编译打包方式是把适配兼容多个设备的执行文件及资源文件合并一个文件，上传和下载的文件则包含了所有的这些文件，导致占用较多的存储空间。

App Thinning是一个关于节省iOS设备存储空间的功能，它可以让iOS设备在安装、更新及运行App等场景中仅下载所需的资源，减少App的占用空间，从而节省设备的存储空间。

根据Apple官方文档的介绍，App Thinning主要有三个机制：


 1. Slicing

 开发者把App安装包上传到AppStore后，Apple服务会自动对安装包切割为不同的应用变体(App variant)，当用户下载安装包时，系统会根据设备型号下载安装对应的单个应用变体。

 2. On-Demand Resources

 ORD(随需资源)是指开发者对资源添加标签上传后，系统会根据App运行的情况，动态下载并加载所需资源，而在存储空间不足时，自动删除这类资源。

 3. Bitcode
 开启Bitcode编译后，可以使得开发者上传App时只需上传Intermediate Representation(中间件)，而非最终的可执行二进制文件。 在用户下载App之前，AppStore会自动编译中间件，产生设备所需的执行文件供用户下载安装。

（喵大(@onevcat)在其博客 [《开发者所需要知道的 iOS 9 SDK 新特性》](http://onevcat.com/2015/06/ios9-sdk/) 中也描述了iOS 9中苹果在App瘦身中所做的一些改进，大家可以转场到那去研读一下。）


其中，Bitcode的机制可以支持动态的进行App Slicing，而对于Apple未来进行硬件升级的措施，此机制可以保证在开发者不重新发布版本的情况下而兼容新的设备。

 Bitcode 是一种中间代码，那它是什么格式的呢？ LLVM 官方文档有介绍这种文件的格式：  [ ***LLVM Bitcode File Format*** ](http://llvm.org/docs/BitCodeFormat.html#llvm-bitcode-file-format) 。

如果你的应用也准备启用 Bitcode 编译机制，就需要注意以下几点：

 1. Xcode 7默认开启 Bitcode ，如果应用开启 Bitcode，那么其集成的其他第三方库也需要是 Bitcode 编译的包才能真正进行 Bitcode 编译
 2. 开启 Bitcode 编译后，编译产生的  `.app`  体积会变大(中间代码，不是用户下载的包)，且  `.dSYM`  文件不能用来崩溃日志的符号化(用户下载的包是 Apple 服务重新编译产生的，有产生新的符号文件)
 3. 通过 Archive 方式上传 AppStore 的包，可以在Xcode的Organizer工具中下载对应安装包的新的符号文件


如何适配？

在上面的错误提示中，提到了如何处理我们遇到的问题：


 > You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target. for architecture arm64

正如开头所说的：


 > 未来， Watch 应用必须包含 Bitcode ，iOS不强制，Mac OS不支持。
但最坑的一点是： Xcode7 及以上版本会默认开启 Bitcode 。

Xcode 7 + 会开启 Bitcode。

也就是说，也两种方法适配：

方法一：更新 library 使包含 Bitcode ，否则会出现以下中的警告；

> (null): URGENT: all bitcode will be dropped because
> '/Users/myname/Library/Mobile
> Documents/com~apple~CloudDocs/foldername/appname/GoogleMobileAds.framework/GoogleMobileAds(GADSlot+AdEvents.o)'
> was built without bitcode. You must rebuild it with bitcode enabled
> (Xcode setting ENABLE_BITCODE), obtain an updated library from the
> vendor, or disable bitcode for this target. Note: This will be an
> error in the future.


甚至有的会报错误，无法通过编译：

> ld: ‘/Users/**/Framework/SDKs/PolymerPay/Library/mobStat/lib**SDK.a(**ForSDK.o)’ does not contain bitcode. You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target. for architecture arm64

或：

 > ld: -undefined and -bitcode_bundle (Xcode setting  `ENABLE_BITCODE` =YES) cannot be used together
clang: error: linker command failed with exit code 1 (use -v to see invocation)

![enter image description here](http://i62.tinypic.com/330vhug.jpg)

无论是警告还是错误，得到的信息是：我们引入的一个第三方库不包含bitcode。

方法二：关闭Bitcode，方法见下图

>  ![enter image description here][15]



  [15]: https://i.imgur.com/OoOogUe.gif

我们可以在”Build Settings”->”Enable Bitcode”选项中看到：

用 Xcode 7+ 新建一个 iOS 程序时， bitcode 选项默认是设置为YES的。现在需要改成NO。



如果我们开启了 bitcode ，在提交包时，下面这个界面也会有个 bitcode 选项：

![enter image description here](http://i60.tinypic.com/5b2q7m.jpg)

那么 SDK 厂商如何支持 bitcode 呢？答案是只要在 Xcode7上重新编译一下就 ok 了。（请确保默认开启的 bitcode 没有去主动关闭）

但是如果仅仅是编译一下，则会出现下类似的如下警告：

![enter image description here](http://image17-c.poco.cn/mypoco/myphoto/20150928/17/1733887242015092817143106.jpg?1462x120_120
)



 > ld: warning: full bitcode bundle could not be generated because 'Lookback(Lookback.o)' was built only with bitcode marker. The library must be generated from Xcode archive build with bitcode enabled (Xcode setting ENABLE_BITCODE)



警告的消除步骤：

模拟器、真机分开打包，SDK在build的时候，让模拟器与真机分开build，模拟器不设置bitcode的参数，真机的加上，然后再合起来。（“合起来”指的是指令集，好比 x86_64 i386 跟 armv7 arm64合起来。）用命令行打包的话 加上这个参数OTHER_CFLAGS=“-fembed-bitcode”。

详情可移步：[ ***How do I xcodebuild a static library with Bitcode enabled?*** ](http://stackoverflow.com/a/31486233/3395008) 


更多信息，请移步

 1. [bitcode 苹果官方文档][16]


  [16]: https://developer.apple.com/library/prerelease/watchos/documentation/IDEs/Conceptual/AppDistributionGuide/AppThinning/AppThinning.html#//apple_ref/doc/uid/TP40012582-CH35-SW2

 2.  WWDC 2015 Session 102: ["Platforms State of the Union"][17]


  [17]: https://developer.apple.com/videos/wwdc/2015/?id=102

 ![enter image description here][18]

  [18]: http://mobileforward.net/wp-content/uploads/2015/06/Screen-Shot-2015-06-12-at-6.57.54-PM-697x351.png


##5.Demo3---iOS9 URL Scheme 适配_引入白名单概念

 [ ***WWDC 2015 Session 703: "Privacy and Your App*** ](https://developer.apple.com/videos/wwdc/2015/?id=703) （ 时间在30：18左右）关于 `URL scheme` 的介绍，指出：


 ![enter image description here][20]

  [20]: https://i.imgur.com/2HxWQqq.png

也就是说：在iOS9中，如果使用 `canOpenURL:` 方法，该方法所涉及到的  `URL scheme` 必须在"Info.plist"中将它们列为白名单，否则不能使用。key叫做LSApplicationQueriesSchemes ，键值内容是

	<key>LSApplicationQueriesSchemes</key>
	<array>
	 <string>urlscheme</string>
	 <string>urlscheme2</string>
	 <string>urlscheme3</string>
	 <string>urlscheme4</string>
	</array> 

白名单上限是50个：

 [ ***WWDC 2015 Session 703: "Privacy and Your App*** ](https://developer.apple.com/videos/wwdc/2015/?id=703) ）有说明：

 > 
 “So for apps that are linked before iOS 9 and are running on iOS 9, they will be given 50 distinct URL schemes.”  --  WWDC 2015 session 703 Privacy and Your App 


 <p><del>
然而，我们却发现了一件意外的事：
当我们在 iOS9-beta（截至本文发布时，iOS9正式版还未发布）中，使用 `openURL:`  方法时，不在白名单中的 URL 会报错 > “This app is not allowed to query for scheme xxx” 。
无论是官方文档还是 WWDC 的视频中都没有提及 `openURL:`  方法的这一变动，所以猜测这是 beta 版本一个 bug ，截至本文发布时，iOS9正式版还未发布，期望在正式版中能得以修复。在此之前，可通过将 `openURL:`  用到的 `URL scheme` 列入白名单来解决这个 bug 。（经测试：iOS9 beta5中已经修复）</del></p>

iOS9中 `openURL:` 方法没有什么实质性的变化，仅仅多了一个确认动作：

![enter image description here](http://i57.tinypic.com/8zjh35.jpg)

苹果为什么要这么做？

在 iOS9 之前，你可以使用 `canOpenURL:` 监测用户手机里到底装没装微信，装没装微博。但是也有一些别有用心的 App ，这些 App 有一张常用 App 的 `URL scheme`，然后他们会多次调用`canOpenURL:` 遍历该表，来监测用户手机都装了什么 App ，比如这个用户装了叫“大姨妈”的App，你就可以知道这个用户是女性，你就可以只推给这个用户女性用品的广告。这是侵犯用户隐私的行为。

这也许就是原因。

本项目中给出了一个演示用的 Demo ，仓库的文件夹叫“Demo3_iOS9URLScheme适配_引入白名单概念”，Demo引用自[ ***LSApplicationQueriesSchemes-Working-Example*** ](https://github.com/gatzsche/LSApplicationQueriesSchemes-Working-Example)

Demo结构如下：

![enter image description here](http://i61.tinypic.com/2hyyuqv.jpg)

主要演示的情景是这样的：

假设有两个App： weixin(微信) and 我的App. 我的App 想监测 weixin(微信) 是否被安装了. "weixin(微信)" 在 info.plist  中定义了 URL scheme :

    <key>CFBundleURLTypes</key>
    <array>
        <dict>
            <key>CFBundleURLSchemes</key>
            <array>
                <string>weixin</string>
            </array>
        </dict>
    </array>

 我的App 想监测 weixin(微信) 是否被安装了 ：

    [[UIApplication sharedApplication]
                        canOpenURL:[NSURL URLWithString:@"weixin(微信)://"]];

即使你安装了微信，在iOS9中，这有可能会返回NO：

因为你需要将 "weixin(微信)" 添加到 “我的App” 的 info.plist 文件中：


    <key>LSApplicationQueriesSchemes</key>
    <array>
        <string>weixin</string>
    </array>

（以上只是为了演示，实际开发中，你不仅需要添加“weixin”还需要“wechat”这两个。具体下文给出表格）


 <p><del>关于 `openURL:` 这个问题，可在 Demo3 中自行测试，如果该 bug 修复了的话，请私信[微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/)，我再来更新本文。（经测试：iOS9 beta5中已经修复）</del></p>


另外，推荐一篇[博文](http://awkwardhare.com/post/121196006730/quick-take-on-ios-9-url-scheme-changes)，其中最关键的是以下部分：

> If you call the “canOpenURL” method on a URL that is not in your whitelist, it will return “NO”, even if there is an app installed that has registered to handle this scheme. A “This app is not allowed to query for scheme xxx” syslog entry will appear.




 <p><del>> If you call the “openURL” method on a URL that is not in your whitelist, it will fail silently. A “This app is not allowed to query for scheme xxx” syslog entry will appear.
</del></p>


### 常见 URL Scheme

如果想一次性集成最常用的微信、新浪微博、QQ、支付宝四者的白名单，则配置如下：

 ```XML
 <key>LSApplicationQueriesSchemes</key>
<array>
    <!-- 微信 URL Scheme 白名单-->
    <string>wechat</string>
    <string>weixin</string>

    <!-- 新浪微博 URL Scheme 白名单-->
    <string>sinaweibohd</string>
    <string>sinaweibo</string>
    <string>sinaweibosso</string>
    <string>weibosdk</string>
    <string>weibosdk2.5</string>

    <!-- QQ、Qzone URL Scheme 白名单-->
    <string>mqqapi</string>
    <string>mqq</string>
    <string>mqqOpensdkSSoLogin</string>
    <string>mqqconnect</string>
    <string>mqqopensdkdataline</string>
    <string>mqqopensdkgrouptribeshare</string>
    <string>mqqopensdkfriend</string>
    <string>mqqopensdkapi</string>
    <string>mqqopensdkapiV2</string>
    <string>mqqopensdkapiV3</string>
    <string>mqzoneopensdk</string>
    <string>wtloginmqq</string>
    <string>wtloginmqq2</string>
    <string>mqqwpa</string>
    <string>mqzone</string>
    <string>mqzonev2</string>
    <string>mqzoneshare</string>
    <string>wtloginqzone</string>
    <string>mqzonewx</string>
    <string>mqzoneopensdkapiV2</string>
    <string>mqzoneopensdkapi19</string>
    <string>mqzoneopensdkapi</string>
    <string>mqzoneopensdk</string>

    <!-- 支付宝  URL Scheme 白名单-->
    <string>alipay</string>
    <string>alipayshare</string>

</array>
 ```
plist 文件看起来会是这样的：

![enter image description here](http://i58.tinypic.com/e5pyee.jpg)

其他平台可在下面的列表中查询：
各平台OpenURL白名单说明

平台名称 | URL Schem  | 补充说明
-------------|-------------|-------------
微信 | wechat,</p> weixin
支付宝 | alipay,</p>alipayshare
QQ | mqqOpensdkSSoLogin, </p>mqqopensdkapiV2,</p>mqqopensdkapiV3,</p>wtloginmqq2,</p>mqq,</p>mqqapi |
QZONE | mqzoneopensdk, </p>mqzoneopensdkapi,</p>mqzoneopensdkapi19,</p>mqzoneopensdkapiV2,</p>mqqOpensdkSSoLogin,</p>mqqopensdkapiV2,</p>mqqopensdkapiV3,</p>wtloginmqq2,</p>mqqapi,</p>mqqwpa，</p>mqzone，</p>mqq | [注:若同时使用QQ和QZONE,则直接添加本格即可]
新浪微博 | sinaweibo,</p>sinaweibohd,</p>sinaweibosso,</p>sinaweibohdsso,</p>weibosdk,</p>weibosdk2.5 | [后两个若导入新浪SDK则需要]
豆瓣 |  无需配置 |
开心网 | 无需配置 |
易信 | yixin,</p> yixinopenapi
Google+ | googlechrome, </p>googlechrome-x-callback,</p>hasgplus4,</p>com.google.gppconsent,</p>com.google.gppconsent.2.2.0,</p>com.google.gppconsent.2.3.0,</p>com.google.gppconsent.2.4.0,</p>com.google.gppconsent.2.4.1 |
人人网 |  renrenapi,</p>renrenios,</p>renreniphone,</p>renren, | 
Facebook | 见下文 |
Twitter | 无需配置 |
Pocket | pocket-oauth-v1|
Pinterest | pinit |
Instagram | instagram |
WhatsApp |  whatsapp |
Line | line |
KakaoTalk | kakaolink |
KaokaoStory | storylink |
LinkedIn | 无需配置 |
Tumblr | 无需配置 |
非平台类 | 无需配置 | ( 如短信，复制，邮件等)




另外， Facebook 的URL Scheme白名单需要注意：

如果 SDK 版本低于 4.5 应补充
```
<key>LSApplicationQueriesSchemes</key>
<array>
    <string>fbapi</string>
    <string>fbapi20130214</string>
    <string>fbapi20130410</string>
    <string>fbapi20130702</string>
    <string>fbapi20131010</string>
    <string>fbapi20131219</string>    
    <string>fbapi20140410</string>
    <string>fbapi20140116</string>
    <string>fbapi20150313</string>
    <string>fbapi20150629</string>
    <string>fbauth</string>
    <string>fbauth2</string>
    <string>fb-messenger-api20140430</string>
</array>
```

如果使用 FBSDKMessengerShareKit，还要加上
```
<string>fb-messenger-platform-20150128</string>
<string>fb-messenger-platform-20150218</string>
<string>fb-messenger-platform-20150305</string>
```

如果使用SDK版本高于4.6，则只需要加上
```
<key>LSApplicationQueriesSchemes</key>
<array>
        <string>fbapi</string>
        <string>fb-messenger-api</string>
        <string>fbauth2</string>
        <string>fbshareextension</string>
</array>
```

 [参考链接](https://developers.facebook.com/docs/ios/ios9) 。


### Q-A

Q：我用xcode7编译的app，如果不在plist里面加scheme，ios9下qq就会不显示，因为我用了qqsdk里的判断是否安装qq的方法，我要是直接下载app store上的，没有加scheme，qq也是能显示。

A：本文中所罗列的新特性，多数情况下指的是 iOS9.X-SDK 新特性，AppStore 的版本是基于 iOS8.X-SDK或 iOS7.X-SDK，所以并不受 iOS9新特性约束。也就是说：**Xcode7给iOS8打设备包不需要白名单也能调用“canOpenURL” ，Xcode7给iOS9设备打的包则不然，Xcode7和iOS9缺一不可，才需要适配URL Scheme。**


那么，如何确认自己项目所使用的 SDK？在Targets->Build Setting-->Architectures


![enter image description here](http://i58.tinypic.com/amsa9u.jpg)

 Q：我们自己的应用跳到微信、支付宝、微博等的URLScheme是固定几个，但是从微信、支付宝、微博跳回到我们的应用的URLScheme可能是成千上万个，那他们那些大厂是如何做这个白名单？

A：白名单策略影响的仅仅是 canOpenURL: 接口，OpenURL: 不受影响，这些大厂只调用 openURL: 所以不受 iOS9 的影响。

Q：文中提到了设置白名单的原因，然而，如果这些别有用心的APP在它自己的白名单列出它关心的APP, 然后依次调用canOpenURL来检测，照样可以监控用户都安装了哪些APP啊？所以我依然不明白苹果这样做得原因。

A：白名单的数目上限是50个。苹果这样子做，使得最多只能检测50个App。

Q：按照文中的适配方法，error原因就没有了的确没问题了，但是还是会打印如下信息：

 ```Objective-C
 -canOpenURL: failed for URL: "XXXXXXXXXX" - error: "(null)"。
 ```

A：这个模拟器的一个 bug，无论使用iOS9的真机还是模拟器均出现该问题，估计 Xcode 后续的升级中会修复掉。

那如何判断日志究竟是 Xcode bug 造成的还是没有适配造成的？看error的值，如果是null，则是 bug。（2015-09-21更）


##6. iPad适配Slide Over 和 Split View

 ![enter image description here](http://cdn1.tnwcdn.com/wp-content/blogs.dir/1/files/2015/06/ew-.gif)
 
【iPad适配Slide Over 和 Split View】
若想适配multi tasking特性，唯一的建议：弃纯代码，改用storyboard、xib，纵观苹果WWDC所有Demo均是如此：


 1. [Mysteries of Auto Layout, Part 1](https://developer.apple.com/videos/wwdc/2015/?id=218)

 2. [What's New in Storyboards](https://developer.apple.com/videos/wwdc/2015/?id=215)

 3. [Implementing UI Designs in Interface Builder](https://developer.apple.com/videos/wwdc/2015/?id=407)

 4. [Getting Started with Multitasking on iPad in iOS 9](https://developer.apple.com/videos/wwdc/2015/?id=205)

 5. [Optimizing Your App for Multitasking on iPad in iOS](https://developer.apple.com/videos/wwdc/2015/?id=212)

## 7.字体间隙变大导致 UI 显示异常

iOS8中，字体是Helvetica，中文的字体有点类似于“华文细黑”。只是苹果手机自带渲染，所以看上去可能比普通的华文细黑要美观。iOS9中，中文系统字体变为了专为中国设计的“苹方” 有点类似于一种word字体“幼圆”。字体有轻微的加粗效果，并且最关键的是字体间隙变大了！

所以很多原本写死了width的label可能会出现“...”的情况：

情况 | 显示 |解释
-------------|------------- |------------- 
XIB |将 label 的 width 写死 | 下面这两张图也可以直观的看出同一个界面，同一个label的变化。
iOS8 | ![enter image description here](http://images2015.cnblogs.com/blog/717809/201509/717809-20150919223903476-176844619.png) | 正常
iOS9 | ![enter image description here](http://images2015.cnblogs.com/blog/717809/201509/717809-20150919223918101-1917717144.png) | 最后四位数字、、、

如果不将 label 的 width 写死，仅仅添加左端约束则右端的四个数字会越界

情况 | 显示 |解释
-------------|------------- |------------- 
XIB | ![enter image description here](http://i60.tinypic.com/292r428.jpg) |如果仅仅添加左端约束
iOS8 | ![enter image description here](http://i58.tinypic.com/2vj92bn.jpg) | 正常
iOS9 | ![enter image description here](http://i62.tinypic.com/2czaq1v.jpg) | “3199”这四个数字越界了

所以为了在界面显示上不出错，就算是固定长度的文字也还是建议使用sizetofit 或者ios向上取整 ceilf() 或者提前计算：


 ```Objective-C
CGSize size = [title sizeWithAttributes:@{NSFontAttributeName: [UIFont systemFontOfSize:14.0f]}];
CGSize adjustedSize = CGSizeMake(ceilf(size.width), ceilf(size.height));
 ```


## 8.升级 Xcode7 后的崩溃与警告

### 旧版本新浪微博 SDK 在 iOS9 上会导致的 Crash

 ```Objective-C
 app was compiled with optimization - stepping may behave oddly; variables may not be available
 ```

打印出来这句话，然后崩溃。多是启动的过程中程序就崩溃。

在iOS9下，新浪微博SDK里面使用的 JSONKit 在部分机型可能导致崩溃。崩溃信息如下图。

![enter image description here](http://wiki.mob.com/wp-content/uploads/2015/09/4062130C-1138-4352-89AF-E518F189A851.png)

解决：更新新浪微博SDK，新浪的SDK最新版做了对iOS9兼容。

### iOS9 下使用 Masonry 会引起崩溃的一种情况
 
在 iOS8（及以前）我们有这样的经验：

 >   `leading 与 left`  、 `trailing 与 right`  在正常情况下是等价的 但是当一些布局是从右至左时(比如阿拉伯文?没有类似的经验) 则会对调，换句话说就是基本可以不理不用，用left和right就好了

（摘自 [《Masonry介绍与使用实践(快速上手Autolayout)》](http://adad184.com/2014/09/28/use-masonry-to-quick-solve-autolayout/) ）


但在概念里，还是一直将 leading 与 left 划为等号，这样做在 iOS8（及以前）上是正常的，但在 iOS9 上这样的观念可能会引起崩溃，比如：

 ```Objective-C
 make.left.equalTo(self.mas_leading).offset(15);
 ```

应该为：

 ```Objective-C
 make.left.equalTo(self.mas_left).offset(15);
 ```

同理 mas_training 也需要改为right

同时也有人反馈说也需要作如下调整否则也会崩溃：

toplayoutGuide 替换成 mas_toplayoutguide
bottomlayoutguide 替换成 mas_bottomlayoutguide

而且使用类似 `make.top.equalTo(topView.mas_baseline).with.offset(5);` 涉及 `mas_baseline` 的语句也会引起崩溃。

暂时的解决方案是

使用 `make.top.equalTo(self.mas_topLayoutGuide).with.offset(5);` 来替换原来的  `self.topLayoutGuide.mas_baseline`  反正效果是一样的

原来的代码：

 ```Objective-C
[self.headerView mas_makeConstraints:^(MASConstraintMaker *make) {
    UIView *topView = (UIView *)self.topLayoutGuide;
    make.top.equalTo(topView.mas_baseline).with.offset(5);
    make.leading.equalTo(self.view.mas_leading).with.offset(10);
    make.right.equalTo(self.view.mas_right).with.offset(-10);
    make.height.equalTo(@34);
}];
 ```

修改后：

 ```Objective-C
[self.headerView mas_makeConstraints:^(MASConstraintMaker *make) {
    make.top.equalTo(self.mas_topLayoutGuide).with.offset(5);
    make.left.equalTo(self.view.mas_left).with.offset(10);
    make.right.equalTo(self.view.mas_right).with.offset(-10);
    make.height.equalTo(@34);
}];
 ```

### Xcode 升级后，旧的状态栏的样式设置方式会引起警告

 ```Objective-C
<Error>: CGContextSaveGState: invalid context 0x0. If you want to see the backtrace, please set CG_CONTEXT_SHOW_BACKTRACE environmental variable.
<Error>: CGContextTranslateCTM: invalid context 0x0. If you want to see the backtrace, please set CG_CONTEXT_SHOW_BACKTRACE environmental variable.
<Error>: CGContextRestoreGState: invalid context 0x0. If you want to see the backtrace, please set CG_CONTEXT_SHOW_BACKTRACE environmental variable.
 ```

出错原因：设置 app 的状态栏样式的时候，使用了旧的方式，在 info.plist 里面的 `View controller-based status bar appearance` 默认会为 YES，即使不设置也是 YES，但一般 iOS6 的时候为了设置状态栏样式，需要将其设为NO，iOS7，8也兼容，但是到了iOS9 就会报警告。

解决办法：

删除原先的设置代码，通常老的设置方式是这样的：

 ```Objective-C
 //设置状态栏的白色
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
 ```

删除的原因见下：

 ```Objective-C
 // Setting the statusBarStyle does nothing if your application is using the default UIViewController-based status bar system.
@property(readwrite, nonatomic) UIStatusBarStyle statusBarStyle NS_DEPRECATED_IOS(2_0, 9_0, "Use -[UIViewController preferredStatusBarStyle]");
- (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle animated:(BOOL)animated NS_DEPRECATED_IOS(2_0, 9_0, "Use -[UIViewController preferredStatusBarStyle]");
 ```


修改方式是在 `Info.plist` 文件中做如下修改：

将 `View controller-based status bar appearance` 删除（默认为 YES），或设置为YES：

对应的 plist 里的 XML源码：

 ```Objective-C
 <key>UIViewControllerBasedStatusBarAppearance</key>
	<true/>
 ```
看起来长这样：

![enter image description here](http://i61.tinypic.com/jrsjnd.jpg)

然后使用新的方式来实现状态栏的样式：


 ```Objective-C
- (UIStatusBarStyle)preferredStatusBarStyle;
- (UIViewController *)childViewControllerForStatusBarStyle;
- (void)setNeedsStatusBarAppearanceUpdate
 ```

比如，你想将状态栏设置为白色，就可以这样写：

 ```Objective-C
//设置状态栏的白色
 -(UIStatusBarStyle)preferredStatusBarStyle
{
    return UIStatusBarStyleLightContent;
}
 ```

记得要 clean 下或者删除应用程序重新运行

#### Demo4---navigationController状态栏样式新的设置方法

如果你按照上面的方法设置了，但还是不行。八成是 rootViewController 设置的问题，你必须设置 rootViewController，编译器才会去 rootViewController 中重载 preferredStatusBarStyle 方法。

另外当你在 appdelegate 中将 navigationController 设为 rootViewController 的时候：

 ```Objective-C
     self.window.rootViewController = self.navigationController;
 ```

因为 rootViewController 变为了 navigationController，你在 ViewController 里重写 preferredStatusBarStyle 方法是不会起作用的。所以最好的方法是：



 ```Objective-C
 - (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"微博@iOS程序犭袁";
    self.navigationController.navigationBar.barStyle = UIBarStyleBlack;
}
 ```


如果你还是想重写 preferredStatusBarStyle 方法来达到作用，那最好使用分类来解决：

第二种方法：

.h文件：

 ```Objective-C
 //
//  UINavigationController+StatusBarStyle.h
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationController (StatusBarStyle)

@end

 ```

.m文件：


 ```Objective-C
 //
//  UINavigationController+StatusBarStyle.m
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import "UINavigationController+StatusBarStyle.h"

@implementation UINavigationController (StatusBarStyle)

- (UIStatusBarStyle)preferredStatusBarStyle
{
    //also you may add any fancy condition-based code here
    return UIStatusBarStyleLightContent;
}

@end
 ```

但最好不要通过 Category 重写 `preferredStatusBarStyle` 的方式来指定 status bar 样式。按照苹果官方的解释：

 > If the name of a method declared in a category is the same as a method in the original class, or a method in another category on the same class (or even a superclass), the behavior is undefined as to which method implementation is used at runtime. This is less likely to be an issue if you’re using categories with your own classes, but can cause problems when using categories to add methods to standard Cocoa or Cocoa Touch classes.

所以推荐第一种的方法，不推荐第二种。

我在仓库里给出了 navigation 的两种设置方法，见Demo4。


 第三种方法：
 
 ```Objective-C
 - (UIViewController *)childViewControllerForStatusBarStyle;
 ```
 
 按照苹果官方的解释：
 
 > If your container view controller derives its status bar style from one of its child view controllers, implement this method and return that child view controller. If you return nil or do not override this method, the status bar style for self is used. If the return value from this method changes, call the setNeedsStatusBarAppearanceUpdate method.
 
 调用 `setNeedsStatusBarAppearanceUpdate` 时，系统默认会去调用application.rootViewController的 `preferredStatusBarStyle` 方法，所以这时候当前自己的 viewController 的 `preferredStatusBarStyle` 方法根本不会被调用。
 
 这个接口很重要，这种情况下 `childViewControllerForStatusBarStyle` 就有用了。一般我们常用 navigationController 作为 rootViewController，利用此接口便可以很方便自订各个 viewController 的 statusBarStyle。 子类化一个 navigationController，并且 override `childViewControllerForStatusBarStyle`
 
 ```Objective-C
 - (UIViewController * _Nullable)childViewControllerForStatusBarStyle {
     return self.topViewController;
 }
 ```
 
 意思就是说不要调用我自己 `application.rootViewController（navigationController）` 的 `preferredStatusBarStyle` 方法，去调用｀childViewControllerForStatusBarStyle｀ 回传的 UIViewController 的 `preferredStatusBarStyle`。这裡回传 self.topViewController 就可以保证当前显示的 viewController 的 `preferredStatusBarStyle` 会被系统调用且正确的显示。

参考链接： [preferredStatusBarStyle isn't called--For anyone using a UINavigationController:](http://stackoverflow.com/a/19513714/3395008) 

### Xcode7 在 debug 状态下也生成 .dSYM 文件引起的警告

Xcode6 的工程升级到 Xcode7上来，会报警告：

![enter image description here](http://i57.tinypic.com/2a5zuia.jpg)

这是 debug 编译时导出符号文件出现的告警，

然而新建的Xcode7工程不会有该问题。

解决方法是让 debug 编译的时候不生成符号文件：

![enter image description here](http://i60.tinypic.com/2e23qyp.jpg)

### Xcode7 无法使用 8.x 系统的设备调试，一运行就报错 `there is an intenal API error` 


![enter image description here](http://cdn.cocimg.com/bbs/attachment/Fid_21/21_296305_92094d6a71e587a.png)

`Xcode7` 调试  `iOS8.x` 的真机，需要确保项目名改为英文，中间含有中文会报错  `there is an intenal API error`

按照下面的步骤检查：

bulid settings  ->    packaging  -> product name   

### 使用了 HTML 的 iframe 元素可能导致无法从 Safari 跳转至 App 

我们都知道，从网易新闻分享一条新闻到QQ，然后从QQ中打开链接再用safari打开链接，在iOS8上，这个时候会跳转到网易新闻App。但是现在（2015年09月23日）版本的网易新闻在 iOS9 就不能正常跳转，会跳转到 App Store 页面并提示要不要打开 App Store。


这是很可能是因为使用了 HTML 的 iframe 元素，并将自定义的链接放进了该元素中

举例说明：

![enter image description here](http://i61.tinypic.com/2wbvok8.jpg)


我之前写的一个 Demo： [模仿 《简书 App》 的效果:在html中跳转到App中的对应页面,并能从App跳转到原来的网址](https://github.com/ChenYilong/CYLExternalURL)，在例子中直接调用自定义链接在 iOS9上是可以跳转到 App 中的，然而，如果用 iframe 元素包起来就会变不可用。

参考链接：


 1.  [HTML 的iframe 标签](http://www.w3school.com.cn/tags/tag_iframe.asp) 
 2.  [iOS 9 safari iframe src with custom url scheme not working](http://stackoverflow.com/questions/31891777/ios-9-safari-iframe-src-with-custom-url-scheme-not-working) 

### iOS9锁屏控制台会打印警告 

加入运行如下示例代码：

 ```Objective-C
- (void)viewDidLoad {
    [super viewDidLoad];
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^(void) {
        //在这个10秒内锁屏
         NSLog(@"准备休眠");
        sleep(10);
        NSLog(@"打印成功");
    });
}
 ```

应用运行过程中锁屏，总是会出现以下提示：


 ```Objective-C
** -[UIApplication _handleNonLaunchSpecificActions:forScene:withTransitionContext:completion:] ** unhandled action -> <FBSSceneSnapshotAction: 0x16da76c0> {
    handler = remote;
    info = <BSSettings: 0x16d80e50> {
        (1) = 5;
    };
}
 ```


当应用处于空闲状态时（无网络请求）锁屏对于用户而言并无较大影响，


但是当应用在执行某个异步任务时（比如下拉刷新一下列表）锁屏，重新解锁进入就可能会发现异步任务失败，控制台也会提示 Error 信息：


 ```Objective-C
** -[UIApplication _handleNonLaunchSpecificActions:forScene:withTransitionContext:completion:] ** unhandled action -> <FBSSceneSnapshotAction: 0x16da76c0> {
    handler = remote;
    info = <BSSettings: 0x16d80e50> {
        (1) = 5;
    };
}
error in __connection_block_invoke_2: Connection interrupted
 ```

以上情况不易复现，但确有发生。

在 iOS8 系统下测试并未发现此问题。

对此并未找到合理的解释和对应的解决办法，如果你有解决方法，欢迎提 PR !

### 在`didFinishLaunchingWithOptions`结束后还没有设置window的`rootViewController`会导致崩溃




 iOS9 不允许在 `didFinishLaunchingWithOptions` 结束了之后，还没有设置 window 的 `rootViewController` 。 也许是 Xcode7 的编译器本身就不支持。

崩溃时的控制台日志提示：

 ```Objective-C
*** Assertion failure in -[UIApplication _runWithMainScene:transitionContext:completion:], /BuildRoot/Library/Caches/com.apple.xbs/Sources/UIKit_Sim/UIKit-3505.16/UIApplication.m:3294

***  Terminating app due to uncaught exception 'NSInternalInconsistencyException', reason: 'Application windows are expected to have a root view controller at the end of application launch'

*** First throw call stack:
/*省略*/
libc++abi.dylib: terminating with uncaught exception of type NSException
(lldb) 
 ```

解决的方法是先设初始化个值，之后再赋值替换掉：



 ```Objective-C
UIWindow *window = [[UIWindow alloc] initWithFrame:[UIScreenmainScreen].bounds];
window.rootViewController = [[UIViewController alloc] init];
 ```




尤其注意一种情况，在 iOS8以前，我们有时候会通过在 AppDelegate 中添加另一个 UIWindow ，并修改其 Level 来达到 addSubview 的效果，因而也不设置 window 的 `rootViewController` ，而是把它直接以视图的形式展示了，则在 iOS8 上是警告，在 iOS9 上就崩溃了。

 ```Objective-C
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor yellowColor];
    [self.window makeKeyAndVisible];
    
    UIWindow *normalWindow = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    normalWindow.backgroundColor = [UIColor blueColor];
    normalWindow.windowLevel = UIWindowLevelAlert;
    [normalWindow makeKeyAndVisible];
    
    return YES;
}
 ```


这种情况，在 `didFinishLaunchingWithOptions` 需要修改原来的策略，将第二个 window 类型改为其他类型，比如 viewController 类型、navigation 类型、tabbarController 类型等。
 

## 9.Demo5、Demo6--- 搜索 API

导入两个 framework，

然后像设置tableView 的 cell 一样设置下每一个“搜索元素”，搜索元素的组成如下：


![enter image description here](http://i57.tinypic.com/144b22w.jpg)


详情见 Demo6 代码。


![enter image description here](http://image17-c.poco.cn/mypoco/myphoto/20150923/21/17338872420150923214730010.gif?370x686_110
)

既然刚才说了搜索元素与 tableView 的 cell 非常相似：那么我们就展示一下如何让 tableView 与 CoreSpotlightSearch 进行结合：

详见 Demo6，Demo6 与 Demo5 的主要差异在于：在点击搜索结果跳转到 App 后，还会进一步根据搜索的内容 push 到相应的详情页中：

![enter image description here](http://image17-c.poco.cn/mypoco/myphoto/20150924/00/17338872420150924001340035.gif?306x572_110
)

## 10.iOS国际化问题：当前设备语言字符串返回有变化。


```
NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
NSArray *allLanguage = [defaults objectForKey:@"AppleLanguages"];
NSString *currentLanguage = [allLanguage objectAtIndex:0];
NSLog(@"The current language is : %@", currentLanguage);
```

iOS 9 之前：以上返回结果：语言字符串代码。例如："zh-Hans"

iOS 9:以上返回结果：语言字符串代码 + 地区代码。例如："zh-Hans-US"

备注：  
1.请注意判断当前语言类型，不要用以下形式的代码了，不然在iOS9上就会遇到坑。

```
if ([currentLanguage isEqualToString:@"zh-Hans"])
```

可以使用：

```
if ([currentLanguage hasPrefix:@"zh-Hans"])
```

另外：对于中文，语言有：

+ 简体中文:zh-Hans
+ 繁体中文:zh-Hant
+ 香港中文:zh-HK
+ 澳门中文:zh-MO
+ 台湾中文:zh-TW
+ 新加坡中文:zh-SG  

**备注：以上iOS9 当前语言字符串返回结果：语言字符串代码 + 地区代码。在某些情况下不是这样，本人手机型号：大陆版电信iPhone5S/A1533/16GB测试结果：zh-HK/zh-TW，在地区为"中国"、"中国香港"、"中国台湾"的时候，显示的还是zh-HK/zh-TW，一旦切换到其它地区，设备语言会自动的切换到中文繁体。请开发人员注意中文的问题！**



## 11.UITableView显示异常

原本在 Xcode6 上完好的项目，在 Xcode7 上一编译， `tableView` 出了两个问题 ：


 1.  代码创建的 `tableView` 无法隐藏 cell 分割线
 2.  `reloadData` 刷新失效；


### 代码创建的 `tableView` 无法隐藏 cell 分割线

iOS9 里面用到 tableView 突然跑出来了很多 cell 的分割线， 但是在用xib创建的 tableview，就不存在这个问题

解决方法是将设置分割线隐藏的方法 `self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;` 写在 `-layoutSubviews` 中：

 ```Objective-C
-(void)layoutSubviews{
    [super layoutSubviews];
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
}
 ```

也有人发现另一种方法，就是每次 reloadData 之前都进行一次设置：设置分割线隐藏，这样也可以解决：



 ```Objective-C
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
   [self.tableView reloadData]
 ```

虽然也可以解决但是不推荐，这样写会给其他人造成困扰：不知所云。


### `reloadData` 刷新失效

现象： `[tableView reloadData]` 无效，有一行 cell 明明改变了但是刷新不出来。


 感觉可能是这个方法和某种新加的特性冲突了，猜测可能是 `reloadData` 的操作被推迟到下一个 `RunLoop` 执行最终失效。

解决的方法是，注释 `[tableView reloadData]` ，改用局部刷新：

 ```Objective-C
[self.tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:UITableViewRowAnimationNone];
 ```

这两个推测均属 Xcode7 的bug，将来 Apple 肯定会修复。


#结束语
如果你在开发中遇到什么新的 iOS9 的坑，或者有什么适配细节本文没有提及，欢迎给本仓库提 pull request。也欢迎在[微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/)  或在“iOS9开发学习交流群：523070828”中交流。

疏漏之处，可前往阅读下[这个网站](http://asciiwwdc.com)，这里有每年 WWDC 演讲的英文记录。

----------


Posted by [微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/)  
原创文章，版权声明：自由转载-非商用-非衍生-保持署名 | [Creative Commons BY-NC-ND 3.0](http://creativecommons.org/licenses/by-nc-nd/3.0/deed.zh)

