//
//  PSAEnrollmentController.h
//  PSACommon
//
//  Created by Pivulski, Nikolai on 12/06/2018.
//

#import <Foundation/Foundation.h>
#import "PSACommon/PSABaseClientActionController.h"

NS_ASSUME_NONNULL_BEGIN

@interface PSAEnrollmentController : PSABaseClientActionController

+ (void)updateDeviceToken:(NSString *)deviceToken;
+ (BOOL)isReadyForEnrollment;
+ (BOOL)isEnrolled;
+ (void)reset;

@end

NS_ASSUME_NONNULL_END
