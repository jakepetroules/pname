//
//  ViewController.h
//  pname
//
//  Created by Jake Petroules on 4/3/12.
//  Copyright (c) 2012 Petroules Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PlatformInformation;

@interface ViewController : UIViewController
{
@private
    NSArray *data;
    PlatformInformation *pi;
}

@property (retain, nonatomic) NSArray *data;

@end
