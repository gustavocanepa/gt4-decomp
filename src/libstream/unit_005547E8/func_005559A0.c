/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00561040(s32, void *, void *);         /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_005559A0_temp_s0 {
    char pad0[0x4];
    s32 unk4;
};

struct func_005559A0_temp_s1 {
    s32 unk0;
    char pad4[0x88];
    s8 unk8C;
};

void func_005559A0(s32 arg0, s32 arg1) {
    struct func_005559A0_temp_s0 *temp_s0;
    void *temp_s1;

    temp_s1 = arg0 + (arg1 * 0x114);
    temp_s0 = temp_s1 + 0x8C;
    func_005A48D8(temp_s0, 0, 0x3C);
    ((struct func_005559A0_temp_s1 *)temp_s1)->unk8C = 0x10;
    temp_s0->unk4 = -1;
    func_00561040(((struct func_005559A0_temp_s1 *)temp_s1)->unk0, temp_s1 + 0xC8, temp_s0);
}
