//
//  FriendViewController.m
//  SearchAPIs
//
//  Created by HeBinghua on 15/7/31.
//  Copyright © 2015年 Ben. All rights reserved.
//

#import "FriendViewController.h"

#import "Person.h"

@interface FriendViewController ()

@property (weak, nonatomic) IBOutlet UILabel *nameLabel;
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation FriendViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.nameLabel.text = self.person.name;
    self.imageView.image = self.person.image;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
