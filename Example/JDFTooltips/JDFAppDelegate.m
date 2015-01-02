//
//  JDFAppDelegate.m
//  JDFTooltips
//
//  Created by CocoaPods on 12/21/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import "JDFAppDelegate.h"

// View Controllers
#import "JDFViewController.h"


@implementation JDFAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    JDFViewController *viewController = [[JDFViewController alloc] init];
    UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:viewController];
    self.window.rootViewController = navigationController;
    [self.window makeKeyAndVisible];
    
    return YES;
}

@end
