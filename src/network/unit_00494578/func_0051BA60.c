#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_0051B9F0(s32);                         /* extern */
s32 func_00535A18(u32);                             /* extern */

extern char D_0064B4B4[];
extern char D_00863770[];
struct func_0051BA60_temp_v0 {
    char pad0[0x10C];
    s32 unk10C;
};

void func_0051BA60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u32 temp_a0;
    u32 var_s0;
    struct func_0051BA60_temp_v0 *temp_v0;

    if (*(s32 *)D_00863770 != 0) {
        var_s0 = 0;
        do {
            temp_a0 = var_s0;
            var_s0 += 1;
            func_0051B9F0(func_00535A18(temp_a0));
        } while (var_s0 < 4U);
    }
    temp_v0 = *(void **)D_0064B4B4;
    if (temp_v0 != NULL) {
        temp_v0->unk10C = 0;
    }
}
