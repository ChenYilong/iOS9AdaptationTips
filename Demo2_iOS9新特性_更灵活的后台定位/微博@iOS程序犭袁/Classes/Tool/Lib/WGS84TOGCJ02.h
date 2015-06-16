//
//  WGS84TOGCJ02.h
//  REFrostedViewControllerExample
//
//  Created by CHENYI LONG on 14-9-21.
//  Copyright (c) 2014年 Roman Efimov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface WGS84TOGCJ02 : NSObject
//判断是否已经超出中国范围
+(BOOL)isLocationOutOfChina:(CLLocationCoordinate2D)location;
//转GCJ-02
+(CLLocationCoordinate2D)transformFromWGSToGCJ:(CLLocationCoordinate2D)wgsLoc;
@end