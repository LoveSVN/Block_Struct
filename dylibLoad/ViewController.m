//
//  ViewController.m
//  dylibLoad
//
//  Created by 张晓亮 on 2019/12/18.
//  Copyright © 2019 张晓亮. All rights reserved.
//

#import "ViewController.h"
#import <dlfcn.h>
#import "Test.h"

@interface ViewController ()
@property(nonatomic,strong)Test *test;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(10 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//
//        NSString *path = [NSString stringWithFormat:@"%@/libQQLib.dylib",[NSBundle mainBundle].bundlePath];
//        NSBundle *pubg = [NSBundle bundleWithPath:path];
//
//        dlopen([path UTF8String],RTLD_NOW);
//        [pubg load];
//    });


    NSInteger x = 10;
//    __block NSInteger x1 = 10;
//    __block NSInteger x2 = 10;

//    self.test.test2 = ^(NSString * _Nonnull title) {
//
//    };
//    [self.test testBlcok:^(NSString * _Nonnull title) {
//
//        NSLog(@"title:%@",title);
//    }];

}


@end
