# iOS9AdaptationTips



iOS9适配系列教程【中文在[页面下方](https://github.com/ChenYilong/iOS9AdaptationTips#1-demo1_ios9网络适配_ats改用更安全的https)】


（截至2015年9月3日共有6篇，后续还将持续更新。更多iOS开发干货，欢迎关注  [微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/) ）


For more infomation ，welcome to follow [my twitter](https://twitter.com/stevechen1010)

> English

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

[摘要]iOS9把所有的http请求都改为https了：iOS9系统发送的网络请求将统一使用TLS 1.2 SSL。采用TLS 1.2 协议，目的是强制增强数据访问安全，而且
系统 Foundation 框架下的相关网络请求，将不再默认使用 Http 等不安全的网络协议，而默认采用 TLS 1.2。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。而这一做法，官方文档称为ATS，全称为App Transport Security，是iOS9的一个新特性。

官方文档 [ ***App Transport Security Technote*** ](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240) 对ATS 的介绍：

![enter image description here](http://i58.tinypic.com/ajsf0j.jpg)


注：有童鞋反映：“服务器已支持TLS 1.2 SSL ，但iOS9上还是不行，还要进行本文提出的适配操作。”那是因为：ATS只信任知名CA颁发的证书，小公司所使用的 self signed certificate，还是会被ATS拦截。对此，建议使用下文中给出的NSExceptionDomains，并将你们公司的域名挂在下面。


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

> TLS 1.2 协议 强制增强数据访问安全 系统 Foundation 框架下的相关网络请求，将不再默认使用 Http 等不安全的网络协议，而默认采用 TLS 1.2。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。

总之：

> 要么咱们iOS程序猿加班，要么后台加班：


方案一：立即让公司的服务端升级使用TLS 1.2，以解析相关数据。

方案二：虽Apple不建议，但可通过在 Info.plist 中声明，倒退回不安全的网络请求依然能让App访问指定http，甚至任意的http，具体做法见gif图，示例Demo见 [Demo1](https://github.com/ChenYilong/iOS9AdaptationTips)

![enter image description here](https://github.com/ChenYilong/iOS9AdaptationTips/blob/master/Demo1_iOS9网络适配_改用更安全的HTTPS/微博%40iOS程序犭袁/http问题.gif)

这也是官方文档和WWDC给出的解决方案：
 1.   [Apple官方文档](https://developer.apple.com/library/prerelease/ios/releasenotes/General/WhatsNewIniOS/Articles/iOS9.html#//apple_ref/doc/uid/TP40016198-DontLinkElementID_13)  ![enter image description here](https://i.imgur.com/eTgSHZY.png)

![enter image description here](http://i61.tinypic.com/ae9tgj.jpg)

 2. [WWDC Session： "Networking with NSURLSession" session（ 【WWDC 2015 session 703, “Privacy and Your App” O网页链接 】, 时间在30:18左右）](https://developer.apple.com/videos/wwdc/2015/?id=703)





![enter image description here](https://i.imgur.com/Tc0fS6p.jpg)

![enter image description here](https://i.imgur.com/v2Tskwh.jpg)
  
![enter image description here](https://cdn-images-1.medium.com/max/800/1*9-VeRXU5SAI6lLZeWLI0hQ.png)


等一下。我的应用使用的是我没有权限控制的CDN (Content Delivery Network)而且它不支持HTTPS。

别担心，Apple都替你考虑好了。关于App Transport Security，每个应用都属于4个大类当中的一类。我们来看看每一个大类都是怎样影响应用的。


|--| 分类名|解释|
-------------|-------------|-------------
1.|HTTPS Only （只有HTTPS）|如果你的应用只基于支持HTTPS的服务器，那么你太幸运了。你的应用不需要做任何改变。但是，注意App Transport Security要求TLS 1.2而且它要求站点使用支持forward secrecy协议的密码。证书也要求是符合ATS规格的。因此慎重检查与你的应用交互的服务器是不是符合ATS的要求非常重要。
2.|Mix & Match（混合）|你的应用与一个不符合ATS要求的服务器工作是很有可能的。在这种情况下，你需要告诉操作系统哪些站点是涉及到的然后在你的应用的 Info.plist文件中指明哪些要求没有达到。
3.|Opt Out（撤销ATS）|如果你在创建一个网页浏览器，那么你有一个更大的麻烦。因为你不可能知道你的用户将要访问那个网页，你不可能指明这些网页是否支持ATS要求且在HTTPS上传输。在这种情况下，除了全部撤销 App Transport Security 没有其它办法。
4.|Opt Out With Exceptions（有着例外的撤销ATS）|当你的应用撤消了App Transport Security,，但同时定义了一些例外。这非常有用就是当你的应用从很多的服务器上取数据，但是也要与一个你可控的API交互。在这种情况下，在应用的Info.plist文件中指定任何加载都是被允许的，但是你也指定了一个或多个例外来表明哪些是必须要求 App Transport Security的。

下面分别做一下介绍：

####1.HTTPS Only （只有HTTPS）
如果你的应用只基于支持HTTPS的服务器，那么你太幸运了。你的应用不需要做任何改变。但是，注意App Transport Security要求TLS 1.2而且它要求站点使用支持forward secrecy协议的密码。证书也要求是符合ATS规格的。因此慎重检查与你的应用交互的服务器是不是符合ATS的要求非常重要。

有人遇到过这样的疑惑：服务器已支持TLS 1.2 SSL ，但iOS9上还是不行，还要进行本文提出的适配操作。


那是因为：ATS只信任知名CA颁发的证书，小公司所使用的 self signed certificate，还是会被ATS拦截。对此，建议使用下文中给出的NSExceptionDomains，并将你们公司的域名挂在下面。

官方文档 [ ***App Transport Security Technote*** ](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240) 对CA颁发的证书要求：

 > Certificates must be signed using a SHA256 or better signature hash algorithm, with either a 2048 bit or greater RSA key or a 256 bit or greater Elliptic-Curve (ECC) key.
Invalid certificates result in a hard failure and no connection



####2.Mix & Match（混合）	
你的应用与一个不符合ATS要求的服务器工作是很有可能的，

当你遇到以下三个不符合 ATS 要求的服务器的域名时：

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
                    <key>NSExceptionAllowsInsecureHTTPLoads</key>
                    <false/>
                </dict>
            </dict>
        </dict>
 ```


 在 plist 文件里显示如下：


 ![enter image description here](http://i60.tinypic.com/24y5q4l.jpg)

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
                    <key>NSTemporaryExceptionAllowsInsecureHTTPLoads</key>
                    <true/>
                    <!--在这里声明所支持的 TLS 最低版本-->
                    <key>NSTemporaryExceptionMinimumTLSVersion</key>
                    <string>TLSv1.1</string>
                </dict>
            </dict>
        </dict>
 ```

 在 plist 文件里显示如下：

 ![enter image description here](http://i62.tinypic.com/352nlhx.jpg)

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

 `NSIncludesSubdomains` 关键字告诉 App Transport Security 这个“例外”（Exception）适用于这个特定域名的所有子域。这个“例外”（Exception）还进一步通过扩展可接受的密码列表来定义这个域名可以使用不支持forward secrecy( `NSExceptionRequiresForwardSecrecy` )  协议的密码。想了解更多关于forward secrecy的信息，推荐去看官方文档  [ ***Apple's technote*** ](https://developer.apple.com/library/prerelease/mac/technotes/App-Transport-Security-Technote/index.html) 。

#### 3. Opt Out（撤销ATS）
上面是比较严谨的做法，指定了能访问哪些特定的HTTP。当然也有暴力的做法：
彻底倒退回不安全的HTTP网络请求，能任意进行HTTP请求，比如你在开发一款浏览器App，或者你想偷懒，或者后台想偷懒，或者公司不给你升级服务器。。。

你可以在Info.plist 配置中改用下面的XML源码：

    <key>NSAppTransportSecurity</key>
    <dict>
        <!--彻底倒退回不安全的HTTP网络请求，能任意进行HTTP请求 (不建议这样做)-->
	    <key>NSAllowsArbitraryLoads</key>
	    <true/>
    </dict>

在 plist 文件里显示如下：

![enter image description here](http://i57.tinypic.com/9uq2c7.jpg)

#### 4. Opt Out With Exceptions（有着例外的撤销ATS）

上面已经介绍了三种情景，还有一种可能你也会遇到：

当你的应用撤消了App Transport Security,，但同时定义了一些“例外”（Exception）。当你的应用从很多的服务器上取数据，但是也要与一个你可控的API交互。在这种情况下，在应用的Info.plist文件中指定任何加载都是被允许的，但是你也指定了一个或多个“例外”（Exception）来表明哪些是必须要求 App Transport Security的。下面是Info.plist文件应该会有的内容：


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


【注：以上在Info.plist配置中的做法已经验证可行，但目前Apple的prerelease版本的官方文档并未提及Info.plist中配置的代码，我将密切关注官方文档，如有提及，再来更新[本文](https://github.com/ChenYilong/iOS9AdaptationTips) .你若发现官方文档有提及了，也可在[微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/)通知下我。】

###Q-A

Q：我用xcode7编译的app，如果不在plist里面加关键字说明，ios9下不能进行网络请求，因为我们服务器并不支持 TLS 1.2 ，我要是直接下载app store上的，什么也没有做，也是能正常网络请求。

A：本文中所罗列的新特性，多数情况下指的是 iOS9.X-SDK 新特性，AppStore 的版本是基于 iOS8.X-SDK或 iOS7.X-SDK，所以并不受 iOS9新特性约束。也就是说：**Xcode7给iOS8打设备包可以请求到网络，Xcode7给iOS9设备打的包请求不到网络，Xcode7和iOS9缺一不可，才需要网络适配ATS。**


那么，如何确认自己项目所使用的 SDK？在Targets->Build Setting-->Architectures


![enter image description here](http://i58.tinypic.com/amsa9u.jpg)

Q：服务器已支持TLS 1.2 SSL ，但iOS9上还是不行，还要进行本文提出的适配操作。


A：那是因为：ATS只信任知名CA颁发的证书，小公司所使用的 self signed certificate，还是会被ATS拦截。对此，建议使用下文中给出的NSExceptionDomains，并将你们公司的域名挂在下面。

官方文档 [ ***App Transport Security Technote*** ](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240) 对CA颁发的证书要求：

 > Certificates must be signed using a SHA256 or better signature hash algorithm, with either a 2048 bit or greater RSA key or a 256 bit or greater Elliptic-Curve (ECC) key.
Invalid certificates result in a hard failure and no connection



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

【前言】未来， Watch 应用必须包含 bitcode ，iOS不强制，Mac OS不支持。
但最坑的一点是： Xcode7 及以上版本会默认开启 bitcode 。

什么是 bitcode ？

Apple 官方文档--[ ***App Distribution Guide – App Thinning (iOS, watchOS)*** ](https://developer.apple.com/library/prerelease/ios/documentation/IDEs/Conceptual/AppDistributionGuide/AppThinning/AppThinning.html#//apple_ref/doc/uid/TP40012582-CH35)是这样定义的：

> Bitcode is an intermediate representation of a compiled program. Apps you upload to iTunes Connect that contain bitcode will be compiled and linked on the App Store. Including bitcode will allow Apple to re-optimize your app binary in the future without the need to submit a new version of your app to the store.

翻译过来就是：

>  bitcode 是被编译程序的一种中间形式的代码。包含 bitcode 配置的程序将会在 App Store 上被编译和链接。 bitcode 允许苹果在后期重新优化我们程序的二进制文件，而不需要我们重新提交一个新的版本到 App Store 上。


在 Xcode简介--- [ ***What’s New in Xcode-New Features in Xcode 7*** ](https://developer.apple.com/library/prerelease/ios/documentation/DeveloperTools/Conceptual/WhatsNewXcode/Articles/xcode_7_0.html)中这样描述：


 > Bitcode. When you archive for submission to the App Store, Xcode will compile your app into an intermediate representation. The App Store will then compile the bitcode down into the 64 or 32 bit executables as necessary.

也就是

 > 当我们提交程序到 App Store上时， Xcode 会将程序编译为一个中间表现形式( bitcode )。然后 App store 会再将这个 bitcode 编译为可执行的64位或32位程序。


再看看这两段描述都是放在App Thinning(App瘦身)一节中，可以看出其与包的优化有关了。喵大(@onevcat)在其博客 [《开发者所需要知道的 iOS 9 SDK 新特性》](http://onevcat.com/2015/06/ios9-sdk/) 中也描述了iOS 9中苹果在App瘦身中所做的一些改进，大家可以转场到那去研读一下。


 Bitcode 是一种中间代码，那它是什么格式的呢？ LLVM 官方文档有介绍这种文件的格式：  [ ***LLVM Bitcode File Format*** ](http://llvm.org/docs/BitCodeFormat.html#llvm-bitcode-file-format) 。



如何适配？

在上面的错误提示中，提到了如何处理我们遇到的问题：


 > You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target. for architecture arm64

正如开头所说的：


 > 未来， Watch 应用必须包含 Bitcode ，iOS不强制，Mac OS不支持。
但最坑的一点是： Xcode7 及以上版本会默认开启 Bitcode 。

Xcode 7 + 会开启 Bitcode。

也就是说，也两种方法适配：

方法一：更新library使包含Bitcode，否则会出现以下中的警告；

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



如果我们开启了bitcode，在提交包时，下面这个界面也会有个 bitcode 选项：

![enter image description here](http://i60.tinypic.com/5b2q7m.jpg)


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

 <p><del>关于 `openURL:` 这个问题，可在 Demo3 中自行测试，如果该 bug 修复了的话，请私信[微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/)，我再来更新本文。（经测试：iOS9 beta5中已经修复）</del></p>


另外，推荐一篇[博文](http://awkwardhare.com/post/121196006730/quick-take-on-ios-9-url-scheme-changes)，其中最关键的是以下部分：

> If you call the “canOpenURL” method on a URL that is not in your whitelist, it will return “NO”, even if there is an app installed that has registered to handle this scheme. A “This app is not allowed to query for scheme xxx” syslog entry will appear.




> If you call the “openURL” method on a URL that is not in your whitelist, it will fail silently. A “This app is not allowed to query for scheme xxx” syslog entry will appear.

###Q-A

Q：我用xcode7编译的app，如果不在plist里面加scheme，ios9下qq就会不显示，因为我用了qqsdk里的判断是否安装qq的方法，我要是直接下载app store上的，没有加scheme，qq也是能显示。

A：本文中所罗列的新特性，多数情况下指的是 iOS9.X-SDK 新特性，AppStore 的版本是基于 iOS8.X-SDK或 iOS7.X-SDK，所以并不受 iOS9新特性约束。也就是说：**Xcode7给iOS8打设备包不需要白名单也能调用“canOpenURL” ，Xcode7给iOS9设备打的包则不然，Xcode7和iOS9缺一不可，才需要网络适配URL Scheme。**


那么，如何确认自己项目所使用的 SDK？在Targets->Build Setting-->Architectures


![enter image description here](http://i58.tinypic.com/amsa9u.jpg)

 

##6. iPad适配Slide Over 和 Split View

 ![enter image description here](http://cdn1.tnwcdn.com/wp-content/blogs.dir/1/files/2015/06/ew-.gif)
 
【iPad适配Slide Over 和 Split View】
若想适配multi tasking特性，唯一的建议：弃纯代码，改用storyboard、xib，纵观苹果WWDC所有Demo均是如此：


 1. [Mysteries of Auto Layout, Part 1](https://developer.apple.com/videos/wwdc/2015/?id=218)

 2. [What's New in Storyboards](https://developer.apple.com/videos/wwdc/2015/?id=215)

 3. [Implementing UI Designs in Interface Builder](https://developer.apple.com/videos/wwdc/2015/?id=407)

 4. [Getting Started with Multitasking on iPad in iOS 9](https://developer.apple.com/videos/wwdc/2015/?id=205)

 5. [Optimizing Your App for Multitasking on iPad in iOS](https://developer.apple.com/videos/wwdc/2015/?id=212)




----------


Posted by [微博@iOS程序犭袁](http://weibo.com/luohanchenyilong/)  
原创文章，版权声明：自由转载-非商用-非衍生-保持署名 | [Creative Commons BY-NC-ND 3.0](http://creativecommons.org/licenses/by-nc-nd/3.0/deed.zh)

