#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004B4628(s32, s32, s32, s32, s32); /* extern */
s32 func_004B67A0();                                /* extern */

extern char D_006B04A8[];
struct func_004B66F0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
};

void func_004B66F0(struct func_004B66F0_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = func_004B67A0();
    temp_v1 = arg0->unk10;
    if (temp_v0 < temp_v1) {
        func_004B4628(arg0->unk14, arg0->unk4, temp_v0, temp_v1 - temp_v0, (s32)D_006B04A8);
        arg0->unk10 = temp_v0;
        return;
    }
    if (temp_v1 < temp_v0) {
        func_004B4628(arg0->unk14, arg0->unk4, temp_v1, temp_v0 - temp_v1, (s32)D_006B04A8);
    }
}
