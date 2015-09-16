//
//  CZNews.h
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CYLNews : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *summary;  //摘要
@property (nonatomic, copy) NSString *img;
@property (nonatomic, copy) NSString *sitename;
@property (nonatomic, assign) long addtime;
@property (nonatomic, copy) NSString *time;

+ (instancetype)newWithDic:(NSDictionary *)dic;

@end
