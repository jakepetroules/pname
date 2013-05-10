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

@synthesize data;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    pi = [[PlatformInformation alloc] init];
    
    NSArray *osData = [[NSArray alloc] initWithObjects:
                       [[NSArray alloc] initWithObjects: [pi operatingSystemName], @"Name", nil],
                       [[NSArray alloc] initWithObjects: [pi operatingSystemVersion], @"Version", nil],
                       [[NSArray alloc] initWithObjects: [pi operatingSystemVersionName], @"Version name", nil],
                       nil];
    
    NSArray *kernelData = [[NSArray alloc] initWithObjects:
                           [[NSArray alloc] initWithObjects: [pi kernelName], @"Name", nil],
                           [[NSArray alloc] initWithObjects: [pi kernelVersion], @"Version", nil],
                           [[NSArray alloc] initWithObjects: [pi kernelBuildString], @"Build string", nil],
                           nil];
    
    NSArray *architecture = [[NSArray alloc] initWithObjects:
                             [[NSArray alloc] initWithObjects: [pi architecture], @"Name", nil],
                             [[NSArray alloc] initWithObjects: [NSString stringWithFormat:@"%d", [pi wordSize]], @"Word size", nil],
                             [[NSArray alloc] initWithObjects: [pi endianness], @"Endianness", nil],
                             nil];
    
    NSArray *hardware = [[NSArray alloc] initWithObjects:
                         [[NSArray alloc] initWithObjects: [pi processorType], @"Processor type", nil],
                         [[NSArray alloc] initWithObjects: [pi hardwarePlatform], @"Hardware platform", nil],
                         nil];
    
    NSMutableArray *network = [[NSMutableArray alloc] initWithObjects:
                        [[NSArray alloc] initWithObjects: [pi hostname], @"Hostname", nil],
                        [[NSArray alloc] initWithObjects: [pi publicIP], @"Public IP", nil],    
                        nil];
    
    int i = 1;
    for (NSString *address in [pi ipAddresses])
    {
        [network insertObject:[[NSArray alloc] initWithObjects: address, [NSString stringWithFormat:@"Address %d", i], nil] atIndex:i];
        i++;
    }
    
    NSArray *extra = [[NSArray alloc] initWithObjects:
                      [[NSArray alloc] initWithObjects: [pi xnuBuildVersion], @"XNU build version", nil],
                      [[NSArray alloc] initWithObjects: [pi systemName], @"iOS system name", nil],
                      [[NSArray alloc] initWithObjects: [pi deviceName], @"iOS device name", nil],
                      nil];
    
    NSArray *uname = [[NSArray alloc] initWithObjects:
                      [[NSArray alloc] initWithObjects: [pi unameSysname], @"-s (sysname)", nil],
                      [[NSArray alloc] initWithObjects: [pi unameMachine], @"-m (machine)", nil],
                      [[NSArray alloc] initWithObjects: [pi unameVersion], @"-v (version)", nil],
                      [[NSArray alloc] initWithObjects: [pi unameRelease], @"-r (release)", nil],
                      [[NSArray alloc] initWithObjects: [pi unameNodename], @"-n (nodename)", nil],
                      nil];
    
    NSArray *sections = [[NSArray alloc] initWithObjects:
                              [[NSArray alloc] initWithObjects: osData, @"Operating system", nil],
                              [[NSArray alloc] initWithObjects: kernelData, @"Kernel", nil],
                              [[NSArray alloc] initWithObjects: architecture, @"Architecture", nil],
                              [[NSArray alloc] initWithObjects: hardware, @"Hardware", nil],
                              [[NSArray alloc] initWithObjects: network, @"Network", nil],
                              [[NSArray alloc] initWithObjects: extra, @"Extra (OS-specific)", nil],
                              [[NSArray alloc] initWithObjects: uname, @"Underlying uname results", nil],
                              nil];
    
    self.data = sections;
    [sections release];
    [osData release];
    [kernelData release];
    [architecture release];
    [hardware release];
    [network release];
    [extra release];
    [uname release];
}

- (void)viewDidUnload
{
    [self.data release];
    [pi release];
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
    [super dealloc];
}

- (NSString*)sectionTitle:(NSInteger)index
{
    return [[self.data objectAtIndex:index] objectAtIndex:1];
}

- (NSArray*)sectionData:(NSInteger)index
{
    return [[self.data objectAtIndex:index] objectAtIndex:0];
}

- (NSString*)itemTitleForIndexPath:(NSIndexPath *)indexPath
{
    return [[[self sectionData:[indexPath section]] objectAtIndex:[indexPath row]] objectAtIndex:1];
}

- (NSString*)itemValueForIndexPath:(NSIndexPath *)indexPath
{
    return [[[self sectionData:[indexPath section]] objectAtIndex:[indexPath row]] objectAtIndex:0];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.data count];
}

- (NSString*)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [self sectionTitle:section];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [[self sectionData:section] count];
}

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *pnameTableIdentifier = @"pnameTableIdentifier";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:pnameTableIdentifier];
    if (cell == nil)
    {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:pnameTableIdentifier] autorelease];
    }
    
    cell.textLabel.text = [self itemTitleForIndexPath:indexPath];
    cell.detailTextLabel.text = [self itemValueForIndexPath:indexPath];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UIAlertView *alert = [[UIAlertView alloc]
                          initWithTitle:[self itemTitleForIndexPath:indexPath]
                          message:[self itemValueForIndexPath:indexPath]
                          delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
    [alert release];
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
