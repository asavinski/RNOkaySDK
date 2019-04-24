
#import "RNOkaySdk.h"

//#import <React/RCTBridgeModule.h>
#import <PSA/PSA.h>

@implementation RNOkaySdk

RCT_EXPORT_MODULE();

//RCT_EXPORT_METHOD(addEvent:(NSString *)name location:(NSString *)location)
////{
////    RCTLogInfo(@"Pretending to create an event %@ at %@", name, location);
////}
//
//RCT_EXTERN_METHOD(addEvent:(NSString *)name location:(NSString *)location date:(nonnull NSNumber *)date)
//
//RCT_EXTERN_METHOD(updateDeviceToken:(NSString *)deviceToken
//                  resolver:(RCTPromiseResolveBlock)resolve
//                  rejecter:(RCTPromiseRejectBlock)reject);
//
//RCT_EXTERN_METHOD(enrollmentProcedure:(NSString *)withHost
//                      installationId: (NSString *)installationId
//                      pubPssBase64: (NSString *)pubPssBase64
//                      resolver:(RCTPromiseResolveBlock)resolve
//                      rejecter:(RCTPromiseRejectBlock)reject);
//
RCT_REMAP_METHOD(isEnrolled,
                 isEnrolledWithResolver:(RCTPromiseResolveBlock)resolve
                 rejecter:(RCTPromiseRejectBlock)reject)
{
    @try{
        BOOL isEnrolled = [PSA isEnrolled];
        resolve(@"is Enrolled");
        
    }
    @catch (NSException *exception) {
        //reject(@"BAD",@"BAD",NSError);
    }
}
////RCT_EXPORT_METHOD(getDeviceName:(RCTResponseSenderBlock)callback){
////    @try{
////        NSString *deviceName = [[UIDevice currentDevice] name];
////        callback(@[[NSNull null], deviceName]);
////    }
////    @catch(NSException *exception){
////        callback(@[exception.reason, [NSNull null]]);
////    }
////}
//
////RCT_EXPORT_METHOD(getDeviceName:(RCTResponseSenderBlock)callback){
////    @try{
////        NSNumber t = PSA.isEnrolled;
////        NSString *deviceName = [[UIDevice currentDevice] name];
////        callback(@[[NSNull null], t]);
////    }
////    @catch(NSException *exception){
////        callback(@[exception.reason, [NSNull null]]);
////    }
////}
//
//RCT_EXTERN_METHOD(isReadyForAuthorization:(RCTPromiseResolveBlock)resolve
//                      rejecter:(RCTPromiseRejectBlock)reject);
//

@end

