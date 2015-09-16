//
//  ViewController.m
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

@import CoreLocation;

static const CLLocationDegrees EmptyLocation = -1000.0;

#import "ViewController.h"
#import "WGS84TOGCJ02.h"

@interface ViewController () <CLLocationManagerDelegate>

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) CLLocation *location;
/* 地理编码器 */
@property (nonatomic, strong) CLGeocoder *geocoder;
@property (nonatomic, strong) CLLocationManager   *locationManager;

@end

@implementation ViewController

#pragma mark - 💤 LazyLoad Method

/**
 *  lazy load _geocoder
 *
 *  @return CLGeocoder
 */
- (CLGeocoder *)geocoder
{
    if (_geocoder == nil) {
        _geocoder = [[CLGeocoder alloc] init];
    }
    return _geocoder;
}

/**
 *  lazy load _location
 *
 *  @return CLLocation
 */
- (CLLocation *)location
{
    if (_location == nil) {
        _location =  [[CLLocation alloc] initWithLatitude:EmptyLocation longitude:EmptyLocation];
    }
    return _location;
}

#pragma mark - ♻️ LifeCycle Method

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"微博@iOS程序犭袁";
    [self addGuideView];
    if (![CLLocationManager locationServicesEnabled]) {
        [self openGPSTips];
    }
    [self initUserLocation];
    // 1. 实例化定位管理器
    self.locationManager = [[CLLocationManager alloc] init];
    // 2. 设置代理
    self.locationManager.delegate = self;
    // 3. 定位精度
    [self.locationManager setDesiredAccuracy:kCLLocationAccuracyBest];
    // 4.请求用户权限：分为：⓵只在前台开启定位⓶在后台也可定位，
    //注意：建议只请求⓵和⓶中的一个，如果两个权限都需要，只请求⓶即可，
    //⓵⓶这样的顺序，将导致bug：第一次启动程序后，系统将只请求⓵的权限，⓶的权限系统不会请求，只会在下一次启动应用时请求⓶
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8) {
        //[_locationManager requestWhenInUseAuthorization];//⓵只在前台开启定位
        [self.locationManager requestAlwaysAuthorization];//⓶在后台也可定位
    }
    // 5.iOS9新特性：将允许出现这种场景：同一app中多个location manager：一些只能在前台定位，另一些可在后台定位（并可随时禁止其后台定位）。
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9) {
        self.locationManager.allowsBackgroundLocationUpdates = YES;
    }
    // 6. 更新用户位置
    [self.locationManager startUpdatingLocation];
}

- (void)dealloc {
    // KVO反注册
    [self removeObserver:self forKeyPath:@"location"];
}

#pragma mark - 🆑 CYL Custom Method

- (void)addGuideView {
    UIView *vw = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 90.f)];
    vw.backgroundColor = [UIColor whiteColor];
    UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(16, 35, vw.frame.size.width, 20)];
    self.titleLabel = titleLabel;
    titleLabel.font = [UIFont boldSystemFontOfSize:18];
    titleLabel.textColor = [UIColor colorWithRed:0 green:150.0/255.0 blue:136.0/255.0 alpha:1.0];
    NSString *title = @"开启后台定位";
    NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:title];
    [text addAttribute:NSForegroundColorAttributeName
                 value:[UIColor redColor]
                 range:NSMakeRange(0, 2)];
    titleLabel.attributedText = text;
    [vw addSubview:titleLabel];
    CGSize size = [title sizeWithAttributes:
                   @{NSFontAttributeName:
                         titleLabel.font}];
    float cellWidth = ceilf(size.width);
    //仅修改titleLabel的宽度,xyh值不变
    titleLabel.frame = CGRectMake(titleLabel.frame.origin.x, titleLabel.frame.origin.y,
                                  cellWidth, titleLabel.frame.size.height);
    UISwitch *backgroundLocationSwitch = [[UISwitch alloc] init];
    backgroundLocationSwitch.on = YES;
    backgroundLocationSwitch.frame = CGRectMake(CGRectGetMaxX(titleLabel.frame)+10,
                                                25, 30, 20);
    [vw addSubview:backgroundLocationSwitch];
    [backgroundLocationSwitch addTarget:self action:@selector(showLineSwitchClicked:) forControlEvents:UIControlEventAllEvents];
    UILabel *subtitleLabel = [[UILabel alloc] init];
    //仅修改subtitleLabel的x,ywh值不变
    subtitleLabel.frame = CGRectMake(titleLabel.frame.origin.x,  CGRectGetMaxY(titleLabel.frame) + 10,
                                     [UIScreen mainScreen].bounds.size.width, 14);
    subtitleLabel.font = [UIFont systemFontOfSize:12];
    subtitleLabel.textColor = [UIColor grayColor];
    subtitleLabel.text = @"获取后台定位权限后，再次手动开启、关闭后台定位";
    [vw addSubview:subtitleLabel];
    [self.view addSubview:vw];
}

- (void)initUserLocation {
    [self addObserver:self forKeyPath:@"location" options:NSKeyValueObservingOptionNew context:nil];
}

- (BOOL)isCoordinateEmpty:(CLLocationCoordinate2D)regionCenter {
    BOOL isCoordinateEmpty = NO;
    if((regionCenter.latitude == EmptyLocation)&&(regionCenter.longitude == EmptyLocation)) {
        isCoordinateEmpty = YES;
    }
    return isCoordinateEmpty;
}

-(void)openGPSTips{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"当前定位服务不可用"
                                                    message:@"请尝试到“设置->隐私->定位服务”中开启定位\n或等待GPS定位成功"
                                                   delegate:self
                                          cancelButtonTitle:nil
                                          otherButtonTitles:nil
                          ];
    [alert show];
    int delayInSeconds = 2;
    dispatch_time_t when = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
    dispatch_after(when, dispatch_get_main_queue(), ^{
        [alert dismissWithClickedButtonIndex:0 animated:YES];
    });
}

#pragma mark - 🎬 Actions Method

- (void)showLineSwitchClicked:(UISwitch *)sender {
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9) {
        NSString *title;
        if(sender.isOn) {
            title = @"开启后台定位";
            self.locationManager.allowsBackgroundLocationUpdates = YES;
        } else {
            title = @"关闭后台定位";
            self.locationManager.allowsBackgroundLocationUpdates = NO;
        }
        NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:title];
        [text addAttribute:NSForegroundColorAttributeName
                     value:[UIColor redColor]
                     range:NSMakeRange(0, 2)];
        self.titleLabel.attributedText = text;
    } else {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil
                                                        message:@"只支持在iOS9及以上系统执行本操作"
                                                       delegate:self
                                              cancelButtonTitle:nil
                                              otherButtonTitles:nil
                              ];
        [alert show];
        int delayInSeconds = 1;
        dispatch_time_t when = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
        dispatch_after(when, dispatch_get_main_queue(), ^{
            [alert dismissWithClickedButtonIndex:0 animated:YES];
        });
        sender.on = YES;
        return;
    }
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
    if ([keyPath isEqualToString:@"location"]) {
        CLLocation *location = change[NSKeyValueChangeNewKey];
        if(self.geocoder.geocoding) { [self.geocoder cancelGeocode]; }
        [self.geocoder reverseGeocodeLocation:location completionHandler:^(NSArray *placemarks, NSError *error)
         {
             if (error == nil && [placemarks count] > 0) {
                 CLPlacemark *placeInfo = [placemarks objectAtIndex:0];
                 NSString *title = [placeInfo.addressDictionary objectForKey:@"Name"];
                 NSString *subTitle = [placeInfo.addressDictionary objectForKey:@"FormattedAddressLines"][0];
                 CLLocationCoordinate2D coordinate = CLLocationCoordinate2DMake(location.coordinate.latitude, location.coordinate.longitude);
                 if(![self isCoordinateEmpty:coordinate]) {
                     UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title message:subTitle delegate:self cancelButtonTitle:nil otherButtonTitles:nil];
                     [alert show];
                     int delayInSeconds = 1;
                     dispatch_time_t when = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
                     dispatch_after(when, dispatch_get_main_queue(), ^{
                         [alert dismissWithClickedButtonIndex:0 animated:YES];
                     });
                 }
                 NSLog(@"位置在：%@", subTitle);
             } else {
                 [self openGPSTips];
             }
         }];
    }
}

#pragma mark - 🔌 CLLocationManagerDelegate Method

/* 更新用户位置，会频繁调用 */
- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
{
    //得到didUpdateCoordinate
    CLLocation *loc = [locations objectAtIndex:0];
    //判断是不是属于国内范围
    if (![WGS84TOGCJ02 isLocationOutOfChina:[loc coordinate]]) {
        //转换后的coord
        CLLocationCoordinate2D didUpdateCoordinate = [WGS84TOGCJ02 transformFromWGSToGCJ:[loc coordinate]];
        self.location =  [[CLLocation alloc] initWithLatitude:didUpdateCoordinate.latitude longitude:didUpdateCoordinate.longitude];
    }
}

/* 检测应用是否开启定位服务 */
- (void)locationManager: (CLLocationManager *)manager
       didFailWithError: (NSError *)error {
    [manager stopUpdatingLocation];
    switch([error code]) {
        case kCLErrorDenied:
            [self openGPSTips];
            break;
        case kCLErrorLocationUnknown:
            break;
        default:
            break;
    }
}

@end