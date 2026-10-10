#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
f32 func_003F36B8(s32);                             /* extern */
f32 func_003F36C8(s32);                             /* extern */
f32 func_003F36D8(s32);                             /* extern */
f32 func_003F36E8(s32);                             /* extern */
f32 func_003F36F8(s32);                             /* extern */
s32 func_0045B8A8(...);                     /* extern */
s32 func_0045C170(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32); /* extern */

struct func_0045B978_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_0045B978(char *arg0, s32 arg1) {
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f26;

    temp_f26 = func_003F36B8(func_0045B8A8());
    temp_f25 = func_003F36C8(func_0045B8A8(arg0, arg1));
    temp_f24 = func_003F36D8(func_0045B8A8(arg0, arg1));
    temp_f23 = func_003F36D8(func_0045B8A8(arg0, arg1)) * 0x1.9999980000000p-3f;
    temp_f22 = func_003F36D8(func_0045B8A8(arg0, arg1)) * 0x1.9999980000000p-3f;
    temp_f21 = func_003F36E8(func_0045B8A8(arg0, arg1));
    temp_f20 = func_003F36F8(func_0045B8A8(arg0, arg1));
    func_0045C170(arg0 + (arg1 * 0x4F0) + 0xC, arg1, ((struct func_0045B978_arg0 *)arg0)->unk8, func_0045B8A8(arg0, arg1), temp_f26, temp_f25, temp_f24, temp_f23, temp_f22, temp_f21, temp_f20);
}

}
