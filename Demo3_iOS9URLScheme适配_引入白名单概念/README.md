# LSApplicationQueriesSchemes-Working-Example
iOS 9 introduces LSApplicationQueriesSchemes to allow apps to query if other apps are installed. This project provides two sample apps TestA and TestB which are querying for each other.

* Both TestA and TestB define a URL Scheme within their info.plist files
* TestA adds TestB and TestB adds TestA to its LSApplicationQueriesSchemes inside info.plist
* Thus both apps are allowed to query for each other. 


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
Facebook | fbauth2 |
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



