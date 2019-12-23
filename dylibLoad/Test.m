//
//  Test.m
//  dylibLoad
//
//  Created by 张晓亮 on 2019/12/21.
//  Copyright © 2019 张晓亮. All rights reserved.
//

#import "Test.h"

@implementation Test
-(void)testBlcok:(void(^)(NSString *title))block {

    block(@"sssssss");
}
@end
