#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4550(s32, s32);            /* extern */

void func_004737A0(s32 arg0, s32 arg1) {
    if (arg1 != 1) {
        func_004A4550(4, 0);
        func_004A4550(5, 0);
        return;
    }
    func_004A4550(4, 2);
    func_004A4550(5, 2);
}
