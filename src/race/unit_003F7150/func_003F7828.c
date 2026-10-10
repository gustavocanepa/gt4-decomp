#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003F9870(void *, s32, s32);            /* extern */
s32 func_003F9D00(void *, s32);                 /* extern */
s32 func_00463BE0(s32);                             /* extern */

struct func_003F7828_arg0 {
    char pad0[0x626];
    u8 unk626;
};

void func_003F7828(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_00463BE0(arg0 + 0x14);
    func_003F9D00(arg0, temp_v0);
    func_003F9870(arg0, temp_v0, ((struct func_003F7828_arg0 *)arg0)->unk626 != 2);
}
