#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00655320[];
struct func_00568080_var_s0 {
    s32 (*unk0)(s32);
    s32 unk4;
};

void func_00568080(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 (*temp_v0)(s32);
    s32 var_s1;
    void *var_s0;

    var_s0 = (void *)(s32)D_00655320;
    var_s1 = 3;
    do {
        temp_v0 = ((struct func_00568080_var_s0 *)var_s0)->unk0;
        if (temp_v0 != NULL) {
            temp_v0(((struct func_00568080_var_s0 *)var_s0)->unk4);
        }
        var_s1 -= 1;
        var_s0 += 8;
    } while (var_s1 >= 0);
}
