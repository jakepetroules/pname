//
//  PlatformInformation.h
//  pname
//
//  Created by Jake Petroules on 4/3/12.
//  Copyright (c) 2012 Petroules Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PlatformInformation : NSObject
{
@private
    NSString *m_unameSysname;
    NSString *m_unameNodename;
    NSString *m_unameRelease;
    NSString *m_unameVersion;
    NSString *m_unameMachine;
}

- (id) init;
- (void) dealloc;

- (NSString*) operatingSystemName;
- (NSString*) operatingSystemVersion;
- (NSString*) operatingSystemVersionName;

- (NSString*) kernelName;
- (NSString*) kernelVersion;
- (NSString*) kernelBuildString;

- (NSString*) architecture;
- (int) wordSize;
- (NSString*) endianness;

- (NSString*) processorType;
- (NSString*) hardwarePlatform;

- (NSString*) hostname;
- (NSArray*) ipAddresses;
- (NSString*) publicIP;

- (NSString*) xnuBuildVersion;
- (NSString*) systemName;
- (NSString*) deviceName;
- (NSString*) uiIdiom;

- (NSString*) unameSysname;
- (NSString*) unameNodename;
- (NSString*) unameRelease;
- (NSString*) unameVersion;
- (NSString*) unameMachine;

@end
