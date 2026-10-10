#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_004A1638(s32);                     /* extern */
s32 func_004AA168(u32);                         /* extern */
s32 func_004AB040(s32);                     /* extern */

struct func_00473380_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    char pad18[0xC];
    s32 unk24;
};

void func_00473380(void *arg0, u32 arg1) {
    u32 var_s1;

    var_s1 = arg1;
    if (((struct func_00473380_arg0 *)arg0)->unk14 == 0) {
        func_00473638();
    }
    if (((struct func_00473380_arg0 *)arg0)->unkC != 0) {
        var_s1 = (var_s1 & 0xFFFFFF) | (((struct func_00473380_arg0 *)arg0)->unk24 << 0x18);
        func_004AB040(9);
    } else if ((((struct func_00473380_arg0 *)arg0)->unk0 != 0) && (((struct func_00473380_arg0 *)arg0)->unk4 == 0)) {
        if ((var_s1 >> 0x18) == 0x80) {
            func_004A1638(9);
        } else {
            func_004AB040(9);
        }
    }
    func_004AA168(var_s1);
}
