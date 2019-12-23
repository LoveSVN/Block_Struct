//
//  CDBlockHeader.h
//  dylibLoad
//
//  Created by 张晓亮 on 2019/12/23.
//  Copyright © 2019 张晓亮. All rights reserved.
//

#import <dlfcn.h>
#ifndef CDBlockHeader_h
#define CDBlockHeader_h
struct CDBlockDescriptor {
    unsigned long int reserved; //8 offset:0x0
    unsigned long int Block_size;//8  0x8
    void * copy; //8 0x10 copy
    void * dispose;//8 0x18 dispose
    char * signature;//8 0x20  signature
};

struct CDBlockDescriptor1 {
    unsigned long int reserved; //8 offset:0x0
    unsigned long int Block_size;//8  0x8
    char * signature; //8 0x10 signature
};

struct CDBlock {
    Class isa; // 0   offset:0x0
    int32_t flags; //4  0x4
    int32_t reserved;//4 0x8
    void *funk;// 8 0x10
    struct CDBlockDescriptor *descriptor;// 8 0x18
    //捕获的变量,....

};

NSString * getBlockDebugDescription(struct CDBlock *blcok);
NSString* getBlock_signature(struct CDBlock *blcok);


NSString * getBlockDebugDescription(struct CDBlock *blcok) {


    NSMutableString *debugDescription = [NSMutableString stringWithFormat:@"\n<%@: %p>\n",blcok->isa,blcok];

    NSString *block_signatur_string = getBlock_signature(blcok);
    [debugDescription appendFormat:@" signature: %@\n",block_signatur_string];

    Dl_info invokeInfo = {0};
    if(dladdr(blcok->funk, &invokeInfo) != 0) {
        [debugDescription appendFormat:@" invoke   : %p\n (%s`%s offset:%p)\n",invokeInfo.dli_saddr,invokeInfo.dli_fname,invokeInfo.dli_sname,invokeInfo.dli_saddr - invokeInfo.dli_fbase];
    }

    Dl_info copyInfo = {0};
    if(dladdr(blcok->descriptor->copy, &copyInfo) != 0) {
        [debugDescription appendFormat:@" copy     : %p\n (%s`%s offset:%p)\n",copyInfo.dli_saddr,copyInfo.dli_fname,copyInfo.dli_sname,copyInfo.dli_saddr - copyInfo.dli_fbase];
    }
    Dl_info disposeInfo = {0};
    if(dladdr(blcok->descriptor->dispose, &disposeInfo) != 0) {
        [debugDescription appendFormat:@" dispose  : %p\n (%s`%s offset:%p)",disposeInfo.dli_saddr,disposeInfo.dli_fname,disposeInfo.dli_sname,disposeInfo.dli_saddr - disposeInfo.dli_fbase];
    }
    return debugDescription;
}

NSString* getBlock_signature(struct CDBlock *blcok) {

    NSString *signature = nil;
    int32_t pp11 =  0x2000000&blcok->flags; //此处已经判断是哪种descriptor了，
    //CDBlockDescriptor signature 偏移0x20。
    //CDBlockDescriptor1 signature 偏移 0x10
    //不知道在外面在获取copy和dispose为什么还要用dladdr来判断
    //终于看到flags的用处了
    if (pp11 != 0) {

        signature = [NSString stringWithCString:blcok->descriptor->signature encoding:NSUTF8StringEncoding];

    } else {
        struct CDBlockDescriptor1 *tmp = blcok->descriptor;
        signature = [NSString stringWithCString:tmp->signature encoding:NSUTF8StringEncoding];
    }

    return signature;
}


#endif /* CDBlockHeader_h */
