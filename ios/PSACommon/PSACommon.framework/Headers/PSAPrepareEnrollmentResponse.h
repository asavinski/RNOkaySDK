//
//  PSAPrepareEnrollmentResponse.h
//  PSACommon
//
//  Created by Sadovsky, Aleksandr on 7/23/18.
//

#import <Foundation/Foundation.h>
#import "EnrollmentActionCodeBlock.h"
#import "PsaCodeBlockResponse.h"

@interface PSAPrepareEnrollmentResponse : PsaCodeBlockResponse<EnrollmentActionCodeBlock *>

@property (strong, readonly, nullable) EnrollmentActionCodeBlock *codeBlock;

@end
