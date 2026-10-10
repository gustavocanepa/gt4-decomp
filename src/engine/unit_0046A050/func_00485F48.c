#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005A3008(s32, s32, s32, s32, void *);
void func_00485F30();
struct func_00485F48_temp_v1 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_00485F48(void **arg0, s32 arg1) {
    s32 var_v0;
    s8 *temp_v1;
    var_v0 = 0;
    temp_v1 = *arg0;
    if (temp_v1 != NULL) {
        var_v0 = func_005A3008(arg1, (s32)(temp_v1 + 0x10), ((struct func_00485F48_temp_v1 *)temp_v1)->unkC, 0x10, func_00485F30);
    }
    return var_v0;
}
