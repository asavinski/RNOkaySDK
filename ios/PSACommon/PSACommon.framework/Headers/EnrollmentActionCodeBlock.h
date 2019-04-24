//
//  EnrollmentActionCodeBlock.h
//  PSACommon
//
//  Created by Sadovsky, Aleksandr on 7/23/18.
//

#import <Foundation/Foundation.h>
#import "ActionCodeBlock.h"

@interface EnrollmentActionCodeBlock : ActionCodeBlock

@property (copy, readonly, nullable) NSString *pubSPS;
@property (assign, readonly) BOOL screenshotEnabled;
@property (copy, readonly, nullable) NSString *pubStorageInitial;

@end
