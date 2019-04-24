//
//  ActionCodeBlock.h
//  PSACommon
//
//  Created by Sadovsky, Aleksandr on 7/23/18.
//

#import <Foundation/Foundation.h>

@interface ActionCodeBlock : NSObject

@property (copy, readonly, nullable) NSString *blockId;
@property (assign, readonly) long lifeTime;
@property (copy, readonly, nullable) NSString *seed;

-(instancetype)initWithDictionary:(nullable NSDictionary<NSString *, id> *)dictionary;

#pragma mark - To override

-(void)initBody:(nullable NSDictionary<NSString *, id> *)dictionary;

@end
