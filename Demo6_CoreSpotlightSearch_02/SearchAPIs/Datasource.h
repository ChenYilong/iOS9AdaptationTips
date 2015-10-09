//
//  Datasource.h
//  SearchAPIs
//
//  Created by HeBinghua on 15/7/31.
//  Copyright © 2015年 Ben. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Person;

@interface Datasource : NSObject

NS_ASSUME_NONNULL_BEGIN

@property (nonatomic, strong) NSArray *people;

- (nullable Person *)friendFromID:(NSString *)id;
- (void)savePeopleToIndex;

NS_ASSUME_NONNULL_END

@end
