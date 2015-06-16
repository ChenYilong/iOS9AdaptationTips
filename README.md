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


