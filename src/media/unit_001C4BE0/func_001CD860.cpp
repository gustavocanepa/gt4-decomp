#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_001CC958();
s32 func_00594470(void *, s32, s32);
struct func_001CD860_arg0 {
    char pad0[0xC];
    s8 unkC;
};

s8 func_001CD860(struct func_001CD860_arg0 *arg0) {
    if (func_00594470(arg0, func_001CC958(), 0xC) == 0) {
        return arg0->unkC;
    }
    return 0;
}

}
