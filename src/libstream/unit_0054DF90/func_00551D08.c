#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00552290(s32);                         /* extern */

extern char D_0064C878[];
struct func_00551D08_var_s0 {
    s32 unk0;
    char pad4[0x4];
    void *unk8;
};

void func_00551D08(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct func_00551D08_var_s0 *var_s0;

    var_s0 = **(void ***)D_0064C878;
    if (var_s0 != NULL) {
        do {
            func_00552290(var_s0->unk0);
            var_s0 = var_s0->unk8;
        } while (var_s0 != NULL);
    }
}
