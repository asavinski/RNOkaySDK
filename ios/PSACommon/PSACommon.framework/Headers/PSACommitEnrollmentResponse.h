//
//  PSACommitEnrollmentResponse.h
//  PSACommon
//
//  Created by Pivulski, Nikolai on 22.06.2018.
//

#import <Foundation/Foundation.h>
#import <PSACommon/PSACommon.h>

NS_ASSUME_NONNULL_BEGIN

@interface PSACommitEnrollmentResponse : PSABaseResponse

@property (copy, readonly, nullable) NSString *skPSS;

@end

NS_ASSUME_NONNULL_END
