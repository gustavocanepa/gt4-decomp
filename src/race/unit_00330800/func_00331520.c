#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00330FD8(s32, s32, s32, s32, s32); /* extern */

struct func_00331520_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

void func_00331520(struct func_00331520_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s3;

    temp_v1 = arg0->unk18;
    if (temp_v1 == 1) {
        temp_v0 = arg0->unk1C;
        if ((temp_v0 == temp_v1) && ((arg1 != temp_v0) || (arg2 != arg1))) {
            var_s3 = 0;
            arg0->unk10 = (s32) ((s32) arg0->unk10 / arg1);
            arg0->unk14 = (s32) ((s32) arg0->unk14 / arg2);
            arg0->unk18 = arg1;
            arg0->unk1C = arg2;
            if (arg2 > 0) {
                do {
                    temp_v0_2 = arg0->unk14;
                    temp_a1 = arg0->unk10 * arg0->unk20;
                    temp_v1_2 = var_s3 * arg0->unk18;
                    var_s3 += 1;
                    func_00330FD8(arg0->unk4 + (temp_a1 * temp_v0_2 * temp_v1_2), temp_a1, arg1, temp_v0_2, 0x10);
                } while (var_s3 < arg2);
            }
        }
    }
}
