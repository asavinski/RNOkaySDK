//
//  PsaCodeBlockResponse.h
//  PSACommon
//
//  Created by Sadovsky, Aleksandr on 7/23/18.
//

#import <Foundation/Foundation.h>
#import "ActionCodeBlock.h"
#import "PSABaseResponse.h"

@interface PsaCodeBlockResponse<CodeBlockType : ActionCodeBlock *> : PSABaseResponse

- (CodeBlockType)getCodeBlock;
- (void)initCodeBlock:(nullable NSDictionary<NSString *, id> *)dictionary;

@end
