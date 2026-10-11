#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EF6B0(void *, s32);
u32 func_004EEF00(void *arg0, s32 arg1) {
    func_004EF9F0(arg0, 1);
    return (u32) ~func_004EF6B0(arg0, arg1) >> 0x1F;
}
