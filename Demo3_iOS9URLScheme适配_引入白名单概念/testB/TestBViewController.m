//
//  TestBViewController.m
//  testB
//
//  Created by Gabriel Gatzsche on 25.06.15.
//  Copyright © 2015 Audanika. All rights reserved.
//

#import "TestBViewController.h"

@interface TestBViewController ()
@property (weak, nonatomic) IBOutlet UILabel *resultLabel;

@end

@implementation TestBViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [_resultLabel sizeToFit];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)buttonPressed:(id)sender {
    BOOL canBeOpened = [[UIApplication sharedApplication]
                        canOpenURL:[NSURL URLWithString:@"TestA.scheme2://"]];
    
    if (canBeOpened) {
        _resultLabel.hidden = NO;
        _resultLabel.text = @"TestA can be opened!";
    }
    else{
        _resultLabel.hidden = NO;
        _resultLabel.text = @"TestA cannot be opened!";
    }

}

@end
