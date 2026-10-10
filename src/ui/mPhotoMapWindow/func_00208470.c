#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00208308();
s32 func_0025C418(s32);
void func_00208470(s32 arg0, s32 arg1) {
    s32 p;
    s32 i;
    p = func_00208308();
    for (i = 0; p != 0 && i != arg1; i++) {
        p = func_0025C418(p);
    }
}
