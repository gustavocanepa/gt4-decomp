#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00440E98(s32, s32);                    /* extern */
s32 func_00441298(s32, s32);                    /* extern */

struct func_00435490_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

void func_00435490(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x7D08;
    func_00440E98(temp_s0, arg2);
    func_00441298(temp_s0, arg3);
    ((struct func_00435490_arg0 *)arg0)->unk81C8 = arg1;
}
