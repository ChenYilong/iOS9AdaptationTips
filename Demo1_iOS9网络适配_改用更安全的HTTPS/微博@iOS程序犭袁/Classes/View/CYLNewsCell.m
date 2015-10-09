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

@property (nonatomic, weak) IBOutlet UILabel *titleView;
@property (nonatomic, weak) IBOutlet UILabel *summaryView;
@property (nonatomic, weak) IBOutlet UILabel *sitenameView;
@property (nonatomic, weak) IBOutlet UIImageView *imgView;
@property (nonatomic, weak) IBOutlet UILabel *addtimeView;

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
