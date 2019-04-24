//
//  PSAUserAnswer.h
//  PSACommon
//
//  Created by Sadovsky, Aleksandr on 8/30/18.
//

#import <Foundation/Foundation.h>
#import <PSACommon/PSACommon.h>

extern NSInteger const PSAUserAnswerTypeAuthResultCancel;
extern NSInteger const PSAUserAnswerTypeAuthResultOK;
extern NSInteger const PSAUserAnswerTypeAuthResultPin;

extern NSString * const PSAUserAnswerOk;
extern NSString * const PSAUserAnswerCancel;

@interface PSAUserAnswer : PSASessionArtifact

- (instancetype)initWithType:(NSNumber *)type valueB64:(NSString *)valueB64;

@end
