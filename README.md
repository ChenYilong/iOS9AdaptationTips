# iOS9AdaptationTips



iOS9适配系列教程

 1. Demo1_iOS9适配系列教程一


> English



How to deal with the SSL in iOS9，One solution is to  do like:
 ![enter image description here][3]

  [3]: https://github.com/ChenYilong/iOS9AdaptationTips/blob/master/Demo1_iOS9适配系列教程一/微博%40iOS程序犭袁/http问题.gif


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


> 中文


TLS 1.2 协议 强制增强数据访问安全
系统 Foundation 框架下的相关网络请求，将不再默认使用 Http 等不安全的网络协议，而默认采用 TLS 1.2。服务器因此需要更新，以解析相关数据。如不更新，可通过在 Info.plist 中声明，倒退回不安全的网络请求。
