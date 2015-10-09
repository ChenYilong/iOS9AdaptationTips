//
//  CYLNews.m
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import "CYLNews.h"

@implementation CYLNews

+ (instancetype)newWithDic:(NSDictionary *)dic {
    CYLNews *news = [CYLNews new];
    for (NSString *pro in [CYLNews getProperties]) {
        [news setValue:dic[pro] forKey:pro];
    }
    return news;
}

- (NSString *)time {
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:self.addtime];
    NSDateFormatter *ndf = [NSDateFormatter new];
    ndf.dateFormat = @"MM-dd HH:mm";
    
    return [ndf stringFromDate:date];
}

/*
 *  获取news对象所有的属性
 */
+ (NSArray *)getProperties {
    return @[ @"title", @"summary", @"img", @"sitename", @"addtime" ];
}

- (NSString *)description{
    return [NSString stringWithFormat:@"<%@,%p>{title:%@}",[self class],self,self.title];
}

@end
