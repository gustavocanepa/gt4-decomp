#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AC798(s32);                             /* extern */
s32 func_004AC7B8(s32);                         /* extern */
u32 func_0057F260(s32);                             /* extern */
s32 func_005A609C(s32, s32);                    /* extern */

struct func_004B0C48_arg1 {
    char pad0[0x48];
    s32 unk48;
};

s32 func_004B0C48(s32 arg0, struct func_004B0C48_arg1 *arg1, s32 arg2, u32 arg3) {
    s32 temp_s3;
    s32 temp_v0;
    s32 var_s4;

    var_s4 = 0;
    temp_s3 = arg1->unk48;
    temp_v0 = func_004AC798(temp_s3);
    if (func_0057F260(temp_v0) < arg3) {
        var_s4 = 1;
        func_005A609C(arg2, temp_v0);
    }
    func_004AC7B8(temp_s3);
    return var_s4;
}
