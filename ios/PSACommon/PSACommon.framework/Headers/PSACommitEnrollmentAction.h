//
//  PSACommitEnrollmentAction.h
//  PSACommon
//
//  Created by Pivulski, Nikolai on 26.06.2018.
//

#import <PSACommon/PSACommon.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PSACommitEnrollmentActionDataSource <PSAClientActionDataSource>
- (PSASecretKey *)pubClient;
@end

@interface PSACommitEnrollmentAction : PSABaseClientAction
@property (weak, nullable) id<PSACommitEnrollmentActionDataSource> dataSource;
@end

NS_ASSUME_NONNULL_END
