//
//  AppDelegate.h
//  pname
//
//  Created by Jake Petroules on 4/3/12.
//  Copyright (c) 2012 Petroules Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ViewController;
@class PlatformInformation;

@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
@private
    PlatformInformation *pi;
}

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) ViewController *viewController;

@end
