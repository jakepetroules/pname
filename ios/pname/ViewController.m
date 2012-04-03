//
//  ViewController.m
//  pname
//
//  Created by Jake Petroules on 4/3/12.
//  Copyright (c) 2012 Petroules Corporation. All rights reserved.
//

#import "ViewController.h"
#import "PlatformInformation.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize infoLabel;
@synthesize scrollView;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    PlatformInformation *pi = [[PlatformInformation alloc] init];
    
    NSString *output = @"";
    
    output = [output stringByAppendingString: @"OPERATING SYSTEM:\n"];
    output = [output stringByAppendingFormat: @"  Name:                 %@\n", [pi operatingSystemName]];
    output = [output stringByAppendingFormat: @"  Version:              %@\n", [pi operatingSystemVersion]];
    output = [output stringByAppendingFormat: @"  Version name:         %@\n", [pi operatingSystemVersionName]];
    output = [output stringByAppendingString: @"\nKERNEL:\n"];
    output = [output stringByAppendingFormat: @"  Name:                 %@\n", [pi kernelName]];
    output = [output stringByAppendingFormat: @"  Version:              %@\n", [pi kernelVersion]];
    output = [output stringByAppendingFormat: @"  Build string:         %@\n", [pi kernelBuildString]];
    output = [output stringByAppendingString: @"\nARCHITECTURE:\n"];
    output = [output stringByAppendingFormat: @"  Name:                 %@\n", [pi architecture]];
    output = [output stringByAppendingFormat: @"  Word size:            %d\n", [pi wordSize]];
    output = [output stringByAppendingFormat: @"  Endianness:           %@\n", [pi endianness]];
    output = [output stringByAppendingString: @"\nHARDWARE:\n"];
    output = [output stringByAppendingFormat: @"  Processor type:       %@\n", [pi processorType]];
    output = [output stringByAppendingFormat: @"  Hardware platform:    %@\n", [pi hardwarePlatform]];
    output = [output stringByAppendingString: @"\nNETWORK:\n"];
    output = [output stringByAppendingFormat: @"  Hostname:             %@\n", [pi hostname]];
    
    for (NSString *address in [pi ipAddresses])
    {
        output = [output stringByAppendingFormat: @"  IP addresses:         %@\n", address];
    }
    
    output = [output stringByAppendingFormat: @"  Public IP:            %@\n", [pi publicIP]];
    output = [output stringByAppendingString: @"\nEXTRA (OS-specific):\n"];
    output = [output stringByAppendingFormat: @"  XNU build version:    %@\n", [pi xnuBuildVersion]];
    output = [output stringByAppendingFormat: @"  iOS system name:      %@\n", [pi systemName]];
    output = [output stringByAppendingFormat: @"  iOS device name:      %@\n", [pi deviceName]];
    output = [output stringByAppendingString: @"\nUnderlying UNAME results:\n"];
    output = [output stringByAppendingFormat: @"  -s (sysname)          %@\n", [pi unameSysname]];
    output = [output stringByAppendingFormat: @"  -o\n"];
    output = [output stringByAppendingFormat: @"  -m (machine)          %@\n", [pi unameMachine]];
    output = [output stringByAppendingFormat: @"  -p\n"];
    output = [output stringByAppendingFormat: @"  -i\n"];
    output = [output stringByAppendingFormat: @"  -M\n"];
    output = [output stringByAppendingFormat: @"  -v (version)          %@\n", [pi unameVersion]];
    output = [output stringByAppendingFormat: @"  -r (release)          %@\n", [pi unameRelease]];
    output = [output stringByAppendingFormat: @"  -n (nodename)         %@\n", [pi unameNodename]];
    
    [infoLabel setText: output];
    [infoLabel sizeToFit];
    [scrollView setContentSize: infoLabel.frame.size];
}

- (void)viewDidUnload
{
    [self setInfoLabel: nil];
    [self setScrollView:nil];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
    {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    }
    else
    {
        return YES;
    }
}

- (void)dealloc
{
    [infoLabel release];
    [scrollView release];
    [super dealloc];
}

@end
