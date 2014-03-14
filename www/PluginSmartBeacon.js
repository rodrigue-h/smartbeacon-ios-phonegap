
/**
 * Constructor.
 *
 */
function PluginSmartBeacon() {
    
};

/**
 * Inits beacon receiver
 * @param {string} beacon region identifier
 * @param {Function} success callback
 * @param {Function} error callback
 * @example
 *      window.plugins.smartbeacon.initWithBeaconIdentifier(function (response) {
 *          
 *      });
 */
PluginSmartBeacon.prototype.initWithBeaconIdentifier = function(regionIdentifier, successCallback, errorCallback) {
    if (errorCallback == null) {
        errorCallback = function () {
        };
    }
    
    if (typeof errorCallback != "function") {
        console.log("CDVPluginSmartBeacon: errorCallback should be a function");
        return;
    }
    
    if (typeof successCallback != "function") {
        console.log("CDVPluginSmartBeacon: successCallback should be a function");
        return;
    }
    
    cordova.exec(successCallback, errorCallback, 'CDVPluginSmartBeacon', 'initWithIdentifier', [regionIdentifier]);
};

/**
 * Phone did enter region with a beacon subscription
 * @param {Function} response callback on result
 */
PluginSmartBeacon.prototype.didEnterRegion = function(callback){

    if (typeof callback != "function") {
        console.log("CDVPluginSmartBeacon: callback should be a function");
        return;
    }
    
    cordova.exec(successCallback, errorCallback, 'CDVPluginSmartBeacon', 'didEnterRegion', []);
};

/**
 * Phone did exit region with a beacon subscription
 * @param {Function} callback
 */
PluginSmartBeacon.prototype.didExitRegion = function(callback) {

    if (typeof callback != "function") {
        console.log("CDVPluginSmartBeacon: callback should be a function");
        return;
    }

    cordova.exec(successCallback, errorCallback, 'CDVPluginSmartBeacon', 'didExitRegion', []);
    
};

/**
 * Did discover beacon subscription
 * @param {Function} callback
 */
PluginSmartBeacon.prototype.didDiscoverBeacons = function(callback){
    
    if (typeof callback != "function") {
        console.log("CDVPluginSmartBeacon: callback should be a function");
        return;
    }
    
    cordova.exec(callback, 'CDVPluginSmartBeacon', 'didDiscoverBeacons', []);
};

module.exports = new PluginSmartBeacon();

