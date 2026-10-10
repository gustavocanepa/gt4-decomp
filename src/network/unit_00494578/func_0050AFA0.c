#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 (*func_0050AFF0())(s32);                    /* extern */

void func_0050AFA0(s32 arg0) {
    if (func_0050AFF0() != NULL) {
        func_0050AFF0()(arg0);
    }
}
