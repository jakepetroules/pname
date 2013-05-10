//
//  AppDelegate.m
//  pname
//
//  Created by Jake Petroules on 4/3/12.
//  Copyright (c) 2012 Petroules Corporation. All rights reserved.
//

#import "AppDelegate.h"

#import "ViewController.h"
#import "PlatformInformation.h"

@implementation AppDelegate

@synthesize window = _window;
@synthesize viewController = _viewController;

- (id)init
{
    self = [super init];
    if (self != nil)
    {
        pi = [[PlatformInformation alloc] init];
    }
    
    return self;
}

- (void)dealloc
{
    [pi release];
    [_window release];
    [_viewController release];
    [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
    {
        self.viewController = [[[ViewController alloc] initWithNibName:@"ViewController_iPhone" bundle:nil] autorelease];
    }
    else
    {
        self.viewController = [[[ViewController alloc] initWithNibName:@"ViewController_iPad" bundle:nil] autorelease];
    }
    
    if ([self.window respondsToSelector:@selector(setRootViewController:)])
    {
        self.window.rootViewController = self.viewController;
    }
    else
    {
        [self.window addSubview:self.viewController.view];
        [self.viewController.view setFrame:[[UIScreen mainScreen] applicationFrame]];
    }
    
    [self.window makeKeyAndVisible];
    return YES;
}

@end
