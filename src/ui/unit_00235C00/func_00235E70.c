#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00235C00();
s32 func_0025C2A0(s32);
s32 func_00265EA8(s32);
s32 func_00235E70(void) {
    s32 res = 0;
    s32 p = func_00235C00();
    while (p != 0) {
        if (func_00265EA8(p) != 0) res = p;
        p = func_0025C2A0(p);
    }
    return res;
}
