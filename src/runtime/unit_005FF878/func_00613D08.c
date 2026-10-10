/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0057B3B0(void *, s32);             /* extern */
s32 func_005A4724(s32, s32, s32);               /* extern */

struct func_00613D08_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
};

void func_00613D08(struct func_00613D08_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk10;
    func_005A4724(arg1, arg0->unkC + (arg0->unk4 * temp_v0), temp_v0);
    func_0057B3B0(arg0, 1);
}
