#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003BB8C8(s32, void *);                 /* extern */
s32 func_003BB958(void *, s32);                     /* extern */

struct func_003B6A30_temp_s1 {
    char pad0[0x40];
    s32 unk40;
};

s32 func_003B6A30(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s3;
    struct func_003B6A30_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0x119C;
    temp_s0 = arg0 + 0x1158;
    temp_s1->unk40 = arg1;
    temp_s3 = func_003BB958(temp_s1, temp_s0);
    if (arg2 != 0) {
        func_003BB8C8(temp_s0, temp_s1);
    }
    return temp_s3;
}
