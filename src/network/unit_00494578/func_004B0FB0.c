#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00550D28(s32, s32, s32, s32);      /* extern */

void func_004B0FB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00550D28(arg2, arg3, 0x8000, arg1);
}
