//
//  CZNews.h
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CYLNews : NSObject

@property (nonatomic, readonly, copy) NSString *title;
@property (nonatomic, readonly, copy) NSString *summary;  //摘要
@property (nonatomic, readonly, copy) NSString *img;
@property (nonatomic, readonly, copy) NSString *sitename;
/*
 *
 之前写的是 long，但是4s-iOS9模拟器上会崩溃，暂时改成 int 类型
 *
 */
@property (nonatomic, readonly, assign) int addtime;
@property (nonatomic, readonly, copy) NSString *time;

+ (instancetype)newWithDic:(NSDictionary *)dic;

@end
