//
//  TestAViewController.m
//  testA
//
//  Created by Gabriel Gatzsche on 25.06.15.
//  Copyright © 2015 Audanika. All rights reserved.
//

#import "TestAViewController.h"

@interface TestAViewController ()
@property (weak, nonatomic) IBOutlet UILabel *resultLabel;
@end

@implementation TestAViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)buttonPressed:(id)sender {
    BOOL canBeOpened = [[UIApplication sharedApplication]
                        canOpenURL:[NSURL URLWithString:@"TestB.scheme2://"]];
    
    if (canBeOpened) {
        _resultLabel.hidden = NO;
        _resultLabel.text = @"TestB can be opened!";
    }
    else{
        _resultLabel.hidden = NO;
        _resultLabel.text = @"TestB cannot be opened!";
    }
}

@end
