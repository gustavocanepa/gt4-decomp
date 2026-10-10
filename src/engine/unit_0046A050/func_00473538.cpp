#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_004A2930(s32, s32, s32, s32);          /* extern */

struct func_00473538_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_00473538(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((struct func_00473538_arg0 *)arg0)->unk14 == 0) {
        func_00473638();
    }
    func_004A2930(arg1, arg2, arg3, ((struct func_00473538_arg0 *)arg0)->unk10);
}
