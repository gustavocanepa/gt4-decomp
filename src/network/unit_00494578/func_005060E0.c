#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005060E0_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x10];
    s32 unk18;
    char pad1C[0x18];
    s32 unk34;
    char pad38[0x64];
    s32 unk9C;
};

s32 func_005060E0(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_v0;

    var_v0 = -0xD;
    if (arg0 != NULL) {
        ((struct func_005060E0_arg0 *)arg0)->unk0 = 1;
        ((struct func_005060E0_arg0 *)arg0)->unk4 = 1;
        func_005A6AB0(arg0 + 8, arg1, 0x14);
        var_v0 = 0;
        ((struct func_005060E0_arg0 *)arg0)->unk18 = arg2;
        ((struct func_005060E0_arg0 *)arg0)->unk34 = arg3;
        if (arg4 != 0) {
            ((struct func_005060E0_arg0 *)arg0)->unk9C = arg4;
        }
    }
    return var_v0;
}
