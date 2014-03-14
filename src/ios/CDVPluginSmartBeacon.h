//
//  CDVPluginSmartBeacon.h
//  SmartGap
//
//  Created by Rod H on 2014-03-14.
//
//

#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>
#import <Cordova/CDVJSON.h>
#import <CoreLocation/CoreLocation.h>
#import <SmartBeacon-SDK/SmartBeacon.h>

@interface CDVPluginSmartBeacon : CDVPlugin <SBLocationManagerDelegate>
{
    NSString* didEnterRegionCallBackId;
    NSString* didExitRegionCallBackId;
    NSString* didDiscoverRegionCallBackId;
}

- (void) initWithIdentifier:(CDVInvokedUrlCommand *)command;
- (void) didEnterRegion:(CDVInvokedUrlCommand *)command;
- (void) didExitRegion:(CDVInvokedUrlCommand *)command;
- (void) didDiscoverBeacons:(CDVInvokedUrlCommand *)command;
@end
