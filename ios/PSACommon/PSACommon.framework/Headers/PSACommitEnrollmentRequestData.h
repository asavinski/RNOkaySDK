//
//  PSACommitEnrollmentRequestData.h
//  PSACommon
//
//  Created by Pivulski, Nikolai on 21.06.2018.
//

#import <PSACommon/PSACommon.h>

NS_ASSUME_NONNULL_BEGIN

@interface PSACommitEnrollmentRequestData : PSABaseRequestData

- (instancetype)initWithNonce:(nullable NSData *)nonce pubClient:(nullable PSASecretKey *)pubClient;

@end

NS_ASSUME_NONNULL_END
