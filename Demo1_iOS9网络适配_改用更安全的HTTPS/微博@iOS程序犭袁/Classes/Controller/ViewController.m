//
//  ViewController.m
//  微博@iOS程序犭袁
//
//  Created by  https://github.com/ChenYilong/iOS9AdaptationTips/ on 15/6/8.
//  Copyright (c) 2015年   http://weibo.com/luohanchenyilong/  . All rights reserved.
//
@import Foundation;

static NSString *const CYL_HTTP_HOST_URL = @"http://news.coolban.com/Api/Index/news_list/app/2/cat/0/limit/20/time/1433735258/type/0?channel=appstore&uuid=64543C0F-89E1-4D63-B947-DB4C504D13B1&net=5&model=iPhone&ver=1.0.5";

#import "ViewController.h"
#import "CYLNews.h"
#import "CYLNewsCell.h"

@interface ViewController ()

@property (nonatomic, strong) NSArray *news;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self loadNews];
}

/*
 *  从网络获取json数据
 */
- (void)loadNews {
    NSURL *url = [NSURL URLWithString:CYL_HTTP_HOST_URL];
    NSURLRequest *request = [NSURLRequest requestWithURL:url cachePolicy:1 timeoutInterval:15];
    [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError) {
        if (!connectionError && data) {
            id array = [NSJSONSerialization JSONObjectWithData:data options:0 error:NULL];
            //字典转模型
            NSMutableArray *mArray = [NSMutableArray array];
            for (NSDictionary *dic in array) {
                CYLNews *news = [CYLNews newWithDic:dic];
                [mArray addObject:news];
            }
            self.news = mArray.copy;
            [self.tableView reloadData];
        } else {
            NSLog(@"%@",connectionError);
        }
    }];
}

#pragma mark - UITableViewDataSource Method

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.news.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    CYLNewsCell *cell = [tableView dequeueReusableCellWithIdentifier:@"news1"];
    CYLNews *news = self.news[indexPath.row];
    cell.news = news;
    return cell;
}

@end
