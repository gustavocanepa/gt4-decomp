#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00450528(s32, s32);                    /* extern */
s32 func_00454DE8();                    /* extern */

struct func_00397768_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
    char pad28[0x2C];
    s32 unk54;
    s32 unk58;
    char pad5C[0x1C];
    s32 unk78;
};

s32 func_00397768(struct func_00397768_arg0 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;

    temp_a0 = arg0->unk4;
    if (temp_a0 != 0) {
        func_00454DE8(temp_a0);
    }
    temp_a0_2 = arg0->unk54;
    if (temp_a0_2 != 0) {
        func_00454DE8(temp_a0_2, arg1);
    }
    temp_a0_3 = arg0->unk58;
    if (temp_a0_3 != 0) {
        func_00454DE8(temp_a0_3, arg1);
    }
    temp_a0_4 = arg0->unk14;
    if (temp_a0_4 != 0) {
        func_00454DE8(temp_a0_4, arg1);
    }
    temp_a0_5 = arg0->unk24;
    if (temp_a0_5 != 0) {
        func_00454DE8(temp_a0_5, arg1);
    }
    temp_a0_6 = arg0->unk78;
    if (temp_a0_6 != 0) {
        func_00450528(temp_a0_6, arg1);
    }
}
