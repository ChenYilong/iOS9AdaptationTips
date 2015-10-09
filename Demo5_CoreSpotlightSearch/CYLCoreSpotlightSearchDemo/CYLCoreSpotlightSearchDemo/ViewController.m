//
//  ViewController.m
//  CYLCoreSpotlightSearchDemo
//
//  Created by 陈宜龙 on 15/9/23.
//  Copyright © 2015年 http://weibo.com/luohanchenyilong/ 微博@iOS程序犭袁. All rights reserved.
//

#import "ViewController.h"
@import CoreSpotlight;
@import MobileCoreServices;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"微博@iOS程序犭袁";
    [self spotLightIndexing];
}


/*
 *
 复杂一点的设置方式 (详情请见： http://is.gd/B8q6eG )
 *
 */
- (void)spotLightIndexing {
    
    NSString *path = [[NSBundle mainBundle] pathForResource:
                      @"data" ofType:@"plist"];
    NSArray *plistArray = [[NSArray alloc] initWithContentsOfFile:path];
    
    [plistArray enumerateObjectsUsingBlock:^(NSDictionary * _Nonnull dict, NSUInteger idx, BOOL * _Nonnull stop) {
        
        CSSearchableItemAttributeSet *attributeSet = [[CSSearchableItemAttributeSet alloc] initWithItemContentType:(NSString *)kUTTypeImage];
        
        // Set properties that describe attributes of the item such as title, description, and image.
        NSString *title = [dict objectForKey:@"title"];
        attributeSet.title = title;
        attributeSet.contentDescription = [NSString stringWithFormat:@"%@的描述，跟微博@iOS程序犭袁 是好朋友",title];
        attributeSet.keywords = @[ title ];
        
        // Create an attribute set for an item
        
        UIImage *image = [UIImage imageNamed:[dict objectForKey:@"image_name"]];
        NSData *imageData = [NSData dataWithData:UIImagePNGRepresentation(image)];
        attributeSet.thumbnailData = imageData;
        
        // Create a searchable item, specifying its ID, associated domain, and the attribute set you created earlier.
        
        CSSearchableItem *item;
        NSString *identifier = [NSString stringWithFormat:@"%@",attributeSet.title];
        
        item = [[CSSearchableItem alloc] initWithUniqueIdentifier:identifier domainIdentifier:@"com.example.apple_sample.theapp.search" attributeSet:attributeSet];
        
        // Index the item.
        
        [[CSSearchableIndex defaultSearchableIndex] indexSearchableItems:@[item] completionHandler: ^(NSError * __nullable error) {
            NSLog(@"Search item indexed");
            
        }];
        
    }];
}
@end
