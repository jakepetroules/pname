//
//  UIDevice+Backports.h
//  pname
//
//  Created by Jake Petroules on 5/10/13.
//
//

#import <UIKit/UIKit.h>

@interface UIDevice (Backports)

- (NSString *)userInterfaceIdiomString;
- (NSString *)nibNameForDeviceFromClassName:(NSString *)className;

@end
