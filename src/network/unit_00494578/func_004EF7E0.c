/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0056F078(void *, s32, s32, s32, s32, s32, s32); /* extern */

struct func_004EF7E0_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

void func_004EF7E0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_0056F078(arg0 + 4, ((struct func_004EF7E0_arg0 *)arg0)->unk7C, arg1, arg2, arg3, arg4, arg5);
}
