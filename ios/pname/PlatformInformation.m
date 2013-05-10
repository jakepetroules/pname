//
//  PlatformInformation.m
//  pname
//
//  Created by Jake Petroules on 4/3/12.
//  Copyright (c) 2012 Petroules Corporation. All rights reserved.
//

#import "PlatformInformation.h"
#include <sys/utsname.h>

@implementation PlatformInformation

- (id)init
{
    self = [super init];
    if (self != nil)
    {
        struct utsname u;
        if (uname(&u) != 0)
        {
            NSString *err = @"Unable to retrieve uname information";
            [NSException raise: err format: err];
        }
        
        m_unameSysname = [NSString stringWithUTF8String: u.sysname];
        m_unameNodename = [NSString stringWithUTF8String: u.nodename];
        m_unameRelease = [NSString stringWithUTF8String: u.release];
        m_unameVersion = [NSString stringWithUTF8String: u.version];
        m_unameMachine = [NSString stringWithUTF8String: u.machine];
    }
    
    return self;
}

- (void)dealloc
{
    [super dealloc];
}

- (NSString *)operatingSystemName
{
    // Do not use this as it'll say "iPhone OS"
    // return [[UIDevice currentDevice] systemName];
    return @"iOS";
}

- (NSString *)operatingSystemVersion
{
    return [[UIDevice currentDevice] systemVersion];
}

- (NSString *)operatingSystemVersionName
{
    return @"unknown";
}

- (NSString *)kernelName
{
    return @"XNU";
}

- (NSString *)kernelVersion
{
    return [self unameRelease];
}

- (NSString *)kernelBuildString
{
    return [self unameVersion];
}

- (NSString *)architecture
{
#if TARGET_IPHONE_SIMULATOR
    // uname gives the arch of the host platform, which is NOT what the simulator
    // actually is - i.e. this will return x86_64 for simulator on a 64-bit platform
    // which is incorrect as the simulator is always 32-bit (for now)... we will use the word
    // size to determine the correct arch and fall back to uname in the (virtually impossible)
    // case we are not 32 or 64 bit
    if ([self wordSize] == 32)
    {
        return @"i386";
    }
    else if ([self wordSize] == 64)
    {
        return @"x86_64";
    }
    else
    {
        return [self unameMachine];
    }
#elif TARGET_OS_IPHONE
    return @"arm";
#else
    #error "Unable to detect processor architecture"
#endif
}

- (int)wordSize
{
    return (sizeof(void*) << 3);
}

- (NSString *)endianness
{
    // Same method as Qt uses
    static const unsigned int one = 1;
    return (*((unsigned char *) &one) == 0) ? @"big" : @"little";
}

- (NSString *)processorType
{
    return @"unknown";
}

- (NSString *)hardwarePlatform
{
    // See this link for providing a more detailed description
    // http://stackoverflow.com/questions/8024833/determine-users-device-using-ios-sdk-and-full-cocoa-touch-objective-c-code
    
    NSString *platform = [[UIDevice currentDevice] model]; // i.e. "iPhone", "iPod touch", "iPad"
#if !TARGET_IPHONE_SIMULATOR
    // for some odd reason this gives us the device model ID (i.e. iPhone4,1) on the real device
    // on simulator it gives the host's architecture (i.e. useless)
    platform = [platform stringByAppendingFormat: @" (%@)", [self unameMachine]];
#endif
    return platform;
}

- (NSString *)hostname
{
    return [self unameNodename];
}

- (NSArray *)ipAddresses
{
    // http://iphonesdksnippets.com/post/2009/09/07/Get-IP-address-of-iPhone.aspx
    // https://github.com/erica/uidevice-extension
    return [[NSArray alloc] init];
}

- (NSString *)publicIP
{
    return @"unknown";
}

- (NSString *)xnuBuildVersion
{
    return @"unknown";
}

- (NSString *)systemName
{
    return [[UIDevice currentDevice] systemName];
}

- (NSString *)deviceName
{
    return [[UIDevice currentDevice] name];
}

- (NSString *)unameSysname
{
    return m_unameSysname;
}

- (NSString *)unameNodename
{
    return m_unameNodename;
}

- (NSString *)unameRelease
{
    return m_unameRelease;
}

- (NSString *)unameVersion
{
    return m_unameVersion;
}

- (NSString *)unameMachine
{
    return m_unameMachine;
}

@end
