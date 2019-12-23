//
//  Test.h
//  dylibLoad
//
//  Created by 张晓亮 on 2019/12/21.
//  Copyright © 2019 张晓亮. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Test : NSObject
@property(nonatomic,strong)void(^test2)(NSString *);
-(void)testBlcok:(void(^)(NSString *title))block;
@end

NS_ASSUME_NONNULL_END
