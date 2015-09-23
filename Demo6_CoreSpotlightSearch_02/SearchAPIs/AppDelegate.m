//
//  AppDelegate.m
//  SearchAPIs
//
//  Created by HeBinghua on 15/7/31.
//  Copyright © 2015年 Ben. All rights reserved.
//

#import "AppDelegate.h"

#import "FriendTableViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    return YES;
}

- (BOOL)application:(nonnull UIApplication *)application continueUserActivity:(nonnull NSUserActivity *)userActivity restorationHandler:(nonnull void (^)(NSArray * _Nullable))restorationHandler {
    
    NSString *friendID = userActivity.userInfo[@"kCSSearchableItemActivityIdentifier"];
    
    UINavigationController *navigationController = (UINavigationController *)self.window.rootViewController;
    [navigationController popToRootViewControllerAnimated:NO];
    FriendTableViewController *friendTableViewController = navigationController.viewControllers.firstObject;
    [friendTableViewController showFriendWithID:friendID];
    
    return YES;
}

@end
