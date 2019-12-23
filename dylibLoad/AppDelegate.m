//
//  AppDelegate.m
//  dylibLoad
//
//  Created by 张晓亮 on 2019/12/18.
//  Copyright © 2019 张晓亮. All rights reserved.
//

#import "AppDelegate.h"

#import "CDBlockHeader.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.

    
    NSInteger x = 10;
    __block NSInteger x1 = 10;
        void (^test1)(NSString *) =  ^(NSString *title) {

            NSLog(@"title:%@",title);
            NSLog(@"%ld  == %s",(long)x);
            NSLog(@"%d  == %s",x,x1);
            x1 = 20;
    //        NSLog(@"%d  == %s",x2,x3);
    //        return @"eeee";
        };

    NSObject *tmp = (NSObject *)test1;

    struct CDBlock *lll = (__bridge_retained struct CDBlock *)test1;
    NSString *blockDebugDescription = getBlockDebugDescription(lll);


//    [tmp debugDescription];


    
    return YES;
}




#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
