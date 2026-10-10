#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0056EDE0(void *, s32, s32, s32, s32);  /* extern */

struct func_004EF8E8_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

void func_004EF8E8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0056EDE0(arg0 + 4, ((struct func_004EF8E8_arg0 *)arg0)->unk7C, arg1, arg2, arg3);
}
