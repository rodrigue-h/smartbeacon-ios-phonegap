//
//  SBLocationManager.h
//  SmartBeacon-SDK
//
//  Created by Ludovic Riviere on 13/01/2014.
//  Copyright (c) 2014 IP Stand. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class SBLocationManager;

/*
 *  SBLocationManagerDelegate
 *
 *  Discussion:
 *    Delegate for SBLocationManager.
 */
@protocol SBLocationManagerDelegate <NSObject>

@optional

/*
 *  beaconManager:didStartMonitoringForRegion:
 *
 *  Discussion:
 *      Invoked when a monitoring for a region started successfully.
 */
- (void)beaconManager:(SBLocationManager *)manager didStartMonitoringForRegion:(CLRegion *)region;


/*
 *  beaconManager:monitoringDidFailForRegion:withError:
 *
 *  Discussion:
 *      Invoked when a region monitoring error has occured. Error types are defined in "CLError.h".
 */
- (void)beaconManager:(SBLocationManager *)manager monitoringDidFailForRegion:(CLRegion *)region withError:(NSError *)error;


/*
 *  beaconManager:didEnterRegion:
 *
 *  Discussion:
 *      Invoked when the user enters a monitored region. This callback will be invoked for every allocated.
 *      Manager will also start ranging beacon for this specific region.
 */
- (void)beaconManager:(SBLocationManager *)manager didEnterRegion:(CLRegion *)region;


/*
 *  beaconManager:didExitRegion:
 *
 *  Discussion:
 *      Invoked when the user exits a monitored region. This callback will be invoked for every allocated.
 *      Manager will also stop ranging beacon for this specific region.
 */
- (void)beaconManager:(SBLocationManager *)manager didExitRegion:(CLRegion *)region;


/*
 *  beaconManager:didDeterminateState:forRegion:
 *
 *  Discussion:
 *      Invoked when there's a state transition for a monitored region or in response to a request
 *      for state via a call to requestStateForAllBeaconRegions.
 */
- (void)beaconManager:(SBLocationManager *)manager didDeterminateState:(CLRegionState)state forRegion:(CLRegion *)region;


/*
 *  beaconManager:didDiscoverBeacons:inRegion:
 *
 *  Discussion:
 *      Invoked when a new set of beacons are available in the specified region.
 *      beacons is an array of CLBeacon objects.
 *      If beacons is empty, it may be assumed no beacons that match the specified region are nearby.
 *      Similarly if a specific beacon no longer appears in beacons, it may be assumed the beacon is no longer received
 *      by the device.
 *
 *
 *  @param manager SBLocationManager instance
 *  @param beacons Array of beacons in range. Beacons are ordered: the nearest first, latest is the farest or as unknown if avoidUnknownStateBeacons is set as NO.
 *  @param region CLRegion instance
 */
- (void)beaconManager:(SBLocationManager *)manager didDiscoverBeacons:(NSArray *)beacons inRegion:(CLRegion *)region;


@end



/*
 *  SBLocationManager
 *
 *  Discussion:
 *    The SBLocationManager object is your entry point to the location service.
 *
 *  @warning *Warning:* You cannot use this class manually. Please use SBInstanceSingleton to communicate
 *     with SBLocationManager object.
 *
 */
@interface SBLocationManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic)           BOOL    enableDebugMode;
@property (nonatomic)           BOOL    avoidUnknownStateBeacons;

@property (nonatomic, weak)     id <SBLocationManagerDelegate> delegate;


/**
 *  addBeaconRegion:
 *
 *  @param beaconReagion A beacon region.
 *
 *  @return YES if beaconRegion has been correctly added in regions pool.
 *
 *  @warning *Warning:* You cannot have multiple region with same identifier.
 *
 */
- (BOOL)addBeaconRegion:(CLBeaconRegion *)beaconReagion;


/**
 *  removeBeaconRegion:
 *
 *  @param beaconReagion A beacon region.
 *
 *  @return YES if beaconRegion has been correctly removed in regions pool.
 *
 */
- (BOOL)removeBeaconRegion:(CLBeaconRegion *)beaconRegion;

/**
 *  startMonitoringAllBeaconRegions
 *
 *  Discussion:
 *      Start (if not) monitoring for all registered beacon regions in pool.
 *      When a beacon region did monitored successfully, it start ranging for this specific region.
 *
 */
- (void)startMonitoringAllBeaconRegions;


/**
 *  stopMonitoringAllBeaconRegions
 *
 *  Discussion:
 *      Stop (if running) monitoring for all registered beacon regions in pool.
 *
 */
- (void)stopMonitoringAllBeaconRegions;


/**
 *  requestStateForAllBeaconRegions
 *
 *  Discussion:
 *      Asynchronously retrieve the cached state of all regions.
 *      The state is returned to the delegate via beaconManager:didDetermineState:forRegion:.
 *
 */
- (void)requestStateForAllBeaconRegions;


/**
 *  nearestBeaconFromArray:
 *
 *  @return Nearest beacon in beacons using avoidUnknownStateBeacons value of SBLocationManager current instance.
 */
- (id)nearestBeaconFromArray:(NSArray *)beacons;


/**
 *  nearestBeaconFromArray:ignoringUnknownState:
 *
 *  @return Nearest beacon in beacons using ignoreUnknwonState
 */
+ (id)nearestBeaconFromArray:(NSArray *)beacons ignoringUnknownState:(BOOL)ignoreUnknwonState;


@end
