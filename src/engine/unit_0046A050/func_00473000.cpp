#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_0049CB68(s32, s32, s32, s32, s32, s32); /* extern */

struct func_00473000_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_00473000(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (((struct func_00473000_arg0 *)arg0)->unk14 == 0) {
        func_00473638();
    }
    func_0049CB68(arg1, arg2, arg3, arg4, 0, 0);
}
