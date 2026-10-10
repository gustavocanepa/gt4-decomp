#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003868E0(void *, s32, s32);
struct func_00386B80_var_s0 {
    char pad0[0x360];
    s32 unk360;
    char pad364[0x8];
    void *unk36C;
};

void func_00386B80(void *arg0, s32 arg1, s32 arg2) {
    s32 var_s1;
    s8 *var_s0;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        ((struct func_00386B80_var_s0 *)var_s0)->unk360 = var_s1;
        var_s1 += 1;
        ((struct func_00386B80_var_s0 *)var_s0)->unk36C = arg0;
        func_003868E0(var_s0, arg1, arg2);
        var_s0 += 0x370;
    } while (var_s1 < 2);
}
