#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00105528(s8 *);                        /* extern */

struct func_00473AA0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00473AA0(s8 *arg0, s32 arg1, s32 arg2) {
    func_00105250(arg0);
    func_00105460((s32) arg0, arg1, arg2);
    ((struct func_00473AA0_arg0 *)arg0)->unk4 = 0;
    func_00105528(arg0);
}
