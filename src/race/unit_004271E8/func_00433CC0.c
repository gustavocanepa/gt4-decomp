#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00433730(s32);                             /* extern */
s32 func_0043A388(s32);                         /* extern */

struct func_00433CC0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_00433CC0(struct func_00433CC0_arg0 *arg0) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;

    var_s2 = 0;
    var_s3 = 0;
    if (arg0->unk8 > 0) {
        var_s1 = 0;
        do {
            var_s2 += 1;
            temp_a0 = arg0->unk4 + var_s1;
            var_s1 += 0x238;
            var_s3 += func_00433730(temp_a0);
        } while (var_s2 < arg0->unk8);
    }
    func_0043A388(var_s3);
}
