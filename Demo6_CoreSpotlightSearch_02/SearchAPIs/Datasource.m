//
//  Datasource.m
//  SearchAPIs
//
//  Created by HeBinghua on 15/7/31.
//  Copyright © 2015年 Ben. All rights reserved.
//

#import "Datasource.h"
#import "Person.h"

@import CoreSpotlight;

@implementation Datasource

- (instancetype)init {
    self = [super init];
    if (self) {
        Person *iOS = [[Person alloc]init];
        iOS.name = @"iOS";
        iOS.id = @"1";
        iOS.image = [UIImage imageNamed:@"ios"];
        
        Person *ben = [[Person alloc]init];
        ben.name = @"Ben";
        ben.id = @"2";
        ben.image = [UIImage imageNamed:@"ben"];
        
        Person *jane = [[Person alloc]init];
        jane.name = @"Jane";
        jane.id = @"3";
        jane.image = [UIImage imageNamed:@"jane"];
        
        Person *pete = [[Person alloc]init];
        pete.name = @"Pete";
        pete.id = @"4";
        pete.image = [UIImage imageNamed:@"pete"];
        
        Person *ray = [[Person alloc]init];
        ray.name = @"Ray";
        ray.id = @"5";
        ray.image = [UIImage imageNamed:@"ray"];
        
        Person *tom = [[Person alloc]init];
        tom.name = @"Tom";
        tom.id = @"6";
        tom.image = [UIImage imageNamed:@"tom"];
        
        _people = @[iOS, ben, jane, pete, ray, tom];
    }
    
    return self;
}

- (nullable Person *)friendFromID:(NSString *)id {
    for(Person *person in self.people) {
        if ([person.id isEqualToString:id]) {
            return person;
        }
    }
    return nil;
}

- (void)savePeopleToIndex {
    NSMutableArray<CSSearchableItem *> *searchableItems = [NSMutableArray array];
    for (Person *person in self.people) {
        CSSearchableItemAttributeSet *attributedSet = [[CSSearchableItemAttributeSet alloc]initWithItemContentType:@"image"];
        attributedSet.title = person.name;
        attributedSet.contentDescription = [NSString stringWithFormat:@"This is an entry all about the interesting person called %@",person.name];
        attributedSet.thumbnailData = UIImagePNGRepresentation(person.image);
        
        CSSearchableItem *item = [[CSSearchableItem alloc]initWithUniqueIdentifier:person.id domainIdentifier:@"com.ios9daybyday.SearchAPIs.people" attributeSet:attributedSet];
        [searchableItems addObject:item];
    }
    
    [[CSSearchableIndex defaultSearchableIndex] indexSearchableItems:searchableItems completionHandler:^(NSError * _Nullable error) {
        if (error != nil) {
            NSLog(@"%@",error.localizedDescription);
        }
    }];
}

@end
