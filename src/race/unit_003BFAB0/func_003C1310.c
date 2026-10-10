#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00621B38[];
s32 func_003C1310(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u32 *var_a1;
    u32 temp_v1;
    u32 var_a0;
    u32 var_a2;

    var_a1 = (u32 *)(s32)D_00621B38;
    var_a0 = *(u32 *)(s32)D_00621B38;
    var_a2 = 0;
    if (var_a0 != 0) {
        do {
            var_a1 += 1;
            temp_v1 = *var_a1;
            var_a2 = (var_a2 < var_a0) ? var_a0 : var_a2;
            var_a0 = temp_v1;
        } while (temp_v1 != 0);
    }
    return (var_a2 + 3) & ~3;
}
