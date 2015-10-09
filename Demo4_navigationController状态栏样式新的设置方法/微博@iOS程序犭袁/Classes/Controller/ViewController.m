//
//  ViewController.m
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"微博@iOS程序犭袁";
    /*
     *
     因为在 ViewController 里已经设置了 self.navigationController.navigationBar.barStyle = UIBarStyleBlack;
     所以不需要使用分类方法，如果不像下面这样在 ViewController 里已经设置，也可采用分类方法来达到设置状态栏的效果。
     *
     */
    self.navigationController.navigationBar.barStyle = UIBarStyleBlack;
}

@end