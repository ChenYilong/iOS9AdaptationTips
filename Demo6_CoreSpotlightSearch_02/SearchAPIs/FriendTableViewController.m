//
//  FriendTableViewController.m
//  SearchAPIs
//
//  Created by HeBinghua on 15/7/31.
//  Copyright © 2015年 Ben. All rights reserved.
//

#import "FriendTableViewController.h"
#import "FriendViewController.h"

#import "Datasource.h"
#import "Person.h"

@interface FriendTableViewController ()

@property (nonatomic, strong) Datasource *datasource;
@property (nonatomic, strong) Person *lastSelectedFriend;

@end

@implementation FriendTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _datasource = [[Datasource alloc]init];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"Cell"];
    [self.datasource savePeopleToIndex];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.datasource.people.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    Person *person = self.datasource.people[indexPath.row];
    cell.textLabel.text = person.name;
    
    return cell;
}

- (void)tableView:(nonnull UITableView *)tableView didSelectRowAtIndexPath:(nonnull NSIndexPath *)indexPath {
    NSInteger selectedIndex = tableView.indexPathForSelectedRow.row;
    self.lastSelectedFriend = self.datasource.people[selectedIndex];
    
    [self performSegueWithIdentifier:@"showFriend" sender:self];
}
#pragma mark - Navigation

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    FriendViewController *destination = segue.destinationViewController;
    destination.person = self.lastSelectedFriend;
}

- (void)showFriendWithID:(NSString *)ID {
    if (ID.length == 0) {
        return;
    }
    
    self.lastSelectedFriend = [self.datasource friendFromID:ID];
    [self performSegueWithIdentifier:@"showFriend" sender:self];
}


@end
