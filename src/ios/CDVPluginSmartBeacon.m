//
//  CDVPluginSmartBeacon.m
//  SmartGap
//
//  Created by Rod H on 2014-03-14.
//
//

#import "CDVPluginSmartBeacon.h"

@implementation CDVPluginSmartBeacon
- (void) initWithIdentifier:(CDVInvokedUrlCommand *)command
{
    NSMutableDictionary* options = (NSMutableDictionary*)[command argumentAtIndex:0];
    NSString *regionIdentifier = [options objectForKey:@"regionIdentifier"];
    SBInstanceSingleton *sbInstance = [SBInstanceSingleton sharedInstance];
    [sbInstance addEntireBeaconRegionWithIdentifier:regionIdentifier];
    [sbInstance startServicesForTarget:self];
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}
- (void) didEnterRegion:(CDVInvokedUrlCommand *)command
{
    NSLog(@"CDVPluginSmartBeacon: subscription to didEnterRegion");
    didEnterRegionCallBackId = command.callbackId;
}
- (void) didExitRegion:(CDVInvokedUrlCommand *)command
{
    NSLog(@"CDVPluginSmartBeacon: subscription to didExitRegion");
    didExitRegionCallBackId = command.callbackId;
}
- (void) didDiscoverBeacons:(CDVInvokedUrlCommand *)command
{
    NSLog(@"CDVPluginSmartBeacon: subscription to didDiscoverBeacons");
    didDiscoverRegionCallBackId = command.callbackId;
}

#pragma mark SBLocationManagerDelegate
- (void)beaconManager:(SBLocationManager *)manager didEnterRegion:(CLRegion *)region
{
    NSLog(@"SBLocationManagerDelegate: did enter region");
    if(didEnterRegionCallBackId)
    {
        CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:result callbackId:didEnterRegionCallBackId];
    }
}

// This method is called when the user exit the listened region.
// It is not immediate, we can wait over 10 seconds before call.
- (void)beaconManager:(SBLocationManager *)manager didExitRegion:(CLRegion *)region
{
    NSLog(@"SBLocationManagerDelegate: did exit region");
    if(didExitRegionCallBackId)
    {
        CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:result callbackId:didExitRegionCallBackId];
    }
}

- (void)beaconManager:(SBLocationManager *)manager didDiscoverBeacons:(NSArray *)beacons inRegion:(CLRegion *)region
{
    NSLog(@"SBLocationManagerDelegate: did discover beacons");
    if(didDiscoverRegionCallBackId)
    {
        CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:result callbackId:didDiscoverRegionCallBackId];
    }
}


@end
