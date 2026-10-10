#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0056FF88(void *, s32, s32, s32, s32, s32); /* extern */

struct func_004EF6D0_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void func_004EF6D0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_0056FF88(arg0 + 0x40, ((struct func_004EF6D0_arg0 *)arg0)->unk80, arg1, arg2, arg3, arg4);
}
