#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00328660(s32);
void func_003286B8(s32);
void func_0022F2F8(s8 *arg0, s32 arg1) {
    s32 *h = (s32 *)(arg0 + 0x84);
    if (arg1 != 0) {
        func_00328660(arg1);
    }
    if (*h != 0) {
        func_003286B8(*h);
    }
    *h = arg1;
}
