//
//  PSAAuthController.h
//  PSA
//
//  Created by Pivulski, Nikolai on 26.06.2018.
//

#import <Foundation/Foundation.h>
#import <PSACommon/PSACommon.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PSAAuthControllerDelegate <PSABaseClientActionControllerDelegate>
- (void)authControllerFinishedAuthPrepare:(PSABaseClientActionController *)controller;
@end

extern NSString * const PSAAuthControllerOkChainType;
extern NSString * const PSAAuthControllerPinChainType;

@interface PSAAuthController : PSABaseClientActionController

@property (nonatomic, weak, nullable) id<PSAAuthControllerDelegate> delegate;

@property (copy, nullable, readonly) NSString *chainType;

- (instancetype)initWithSessionId:(NSNumber *)sessionId;

- (void)commitAuth:(nullable NSString *)userAnswer;
- (void)cancelAuth;

@end

NS_ASSUME_NONNULL_END
