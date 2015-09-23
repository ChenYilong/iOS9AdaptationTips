//
//  UINavigationController+StatusBarStyle.m
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import "UINavigationController+StatusBarStyle.h"

@implementation UINavigationController (StatusBarStyle)

/*
 *
 因为在 ViewController 里已经设置了 self.navigationController.navigationBar.barStyle = UIBarStyleBlack;
 所以不需要使用下面的分类方法，如果不在 ViewController 里已经设置，可采用下面的分类方法来达到设置状态栏的效果。
 *
 */
 
//- (UIStatusBarStyle)preferredStatusBarStyle
//{
//    //also you may add any fancy condition-based code here
//    return UIStatusBarStyleLightContent;
//}

@end
