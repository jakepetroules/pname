//
//  UIDevice+Backports.m
//  pname
//
//  Created by Jake Petroules on 5/10/13.
//
//

#import "UIDevice+Backports.h"
#import <objc/runtime.h>

@implementation UIDevice (Backports)

id userInterfaceIdiomSafe(id self, SEL _cmd)
{
    return UIUserInterfaceIdiomPhone;
}

+ (void)load
{
    SEL uiIdiomSelector = @selector(userInterfaceIdiom);
    if (![UIDevice instancesRespondToSelector:uiIdiomSelector])
    {
        class_addMethod([UIDevice class], uiIdiomSelector, (IMP)userInterfaceIdiomSafe, "@@:");
    }
}

- (NSString *)userInterfaceIdiomString
{
    switch ([self userInterfaceIdiom])
    {
        case UIUserInterfaceIdiomPhone:
            return @"iPhone";
        case UIUserInterfaceIdiomPad:
            return @"iPad";
        default:
            return @"unknown";
    }
}

- (NSString *)nibNameForDeviceFromClassName:(NSString *)className
{
    return [className stringByAppendingFormat:@"_%@", [self userInterfaceIdiomString]];
}

@end
