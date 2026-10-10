#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004628C0(s32);                             /* extern */
s32 func_00559B60(s32, s32);                    /* extern */
s32 func_00559C30(s32, s32);                    /* extern */
s32 func_00559CC8();                                /* extern */

struct func_00462900_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    char pad14[0xC];
    s32 unk20;
};

s32 func_00462900(struct func_00462900_arg0 *arg0) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0->unk20 == 0) {
        temp_s0 = func_004628C0(arg0->unk4);
        temp_v0 = func_00559CC8();
        arg0->unk20 = temp_v0;
        func_00559B60(temp_v0, temp_s0);
        func_00559C30(arg0->unk20, arg0->unk10);
    }
}
