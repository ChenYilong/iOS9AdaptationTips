//
//  CYLNewsCell.m
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//

#import "CYLNewsCell.h"
#import "CYLNews.h"
#import "UIImageView+WebCache.h"

@interface CYLNewsCell ()

@property (weak, nonatomic) IBOutlet UILabel *titleView;
@property (weak, nonatomic) IBOutlet UILabel *summaryView;
@property (weak, nonatomic) IBOutlet UILabel *sitenameView;
@property (weak, nonatomic) IBOutlet UIImageView *imgView;
@property (weak, nonatomic) IBOutlet UILabel *addtimeView;

@end

@implementation CYLNewsCell

- (void)setNews:(CYLNews *)news{
    _news = news;
    self.titleView.text = news.title;
    self.summaryView.text = news.summary;
    self.sitenameView.text = news.sitename;
    [self.imgView sd_setImageWithURL:[NSURL URLWithString:news.img]];
    self.addtimeView.text = news.time;
}

@end
