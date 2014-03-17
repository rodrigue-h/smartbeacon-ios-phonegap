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
}

@property (nonatomic, copy) NSString *didEnterRegionCallBackId;
@property (nonatomic, copy) NSString *didExitRegionCallBackId;
@property (nonatomic, copy) NSString *didDiscoverRegionCallBackId;

- (void) initWithIdentifier:(CDVInvokedUrlCommand *)command;
- (void) didEnterRegion:(CDVInvokedUrlCommand *)command;
- (void) didExitRegion:(CDVInvokedUrlCommand *)command;
- (void) didDiscoverBeacons:(CDVInvokedUrlCommand *)command;
@end
