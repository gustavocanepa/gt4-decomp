#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

int func_00535780(int);
int func_00536CF8(void);
int func_00536D38(void);
struct func_0052EBB0_temp_v0 {
    char pad0[0x64];
    s32 (*unk64)(s8, s32, s32, s32, s32, s32, s32);
};

s32 func_0052EBB0(s8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_v0_2;
    s32 var_s1;
    s32 var_v0;
    struct func_0052EBB0_temp_v0 *temp_v0;

    var_s1 = 0;
    var_v0 = func_00535780(func_00536CF8());
    if (var_v0 == 0) {
        temp_v0 = *(void **)0x64B4B4;
        if (temp_v0 != NULL) {
            var_s1 = temp_v0->unk64(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        }
        temp_v0_2 = func_00535780(func_00536D38());
        var_v0 = (temp_v0_2 == 0) ? var_s1 : temp_v0_2;
    }
    return var_v0;
}
