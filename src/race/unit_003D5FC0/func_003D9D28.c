#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003D9B20(void *);                      /* extern */
s32 func_003F1BD8(s32, s32, s32, u32);      /* extern */

struct func_003D9D28_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_003D9D28(struct func_003D9D28_arg0 *arg0, u32 arg1) {
    s32 temp_s0;

    if (arg1 < 5U) {
        temp_s0 = func_003F1BD8(arg0->unk10, 4, 0, arg1);
        func_003D9B20(arg0);
        return temp_s0 > 0;
    }
    return 0;
}
