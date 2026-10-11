#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0013BD50(void *, void *);              /* extern */

struct func_005C6D40_arg2 {
    char pad0[0x4];
    s32 unk4;
};

struct func_005C6D40_var_s0 {
    char pad0[0x4];
    s32 unk4;
};

void *func_005C6D40(void *arg0, s32 arg1, struct func_005C6D40_arg2 *arg2) {
    s32 var_s1;
    void *var_s0;

    var_s1 = arg1;
    var_s0 = arg0;
    if (var_s1 != 0) {
        do {
            if (var_s0 != NULL) {
                func_0013BD50(var_s0, arg2);
                ((struct func_005C6D40_var_s0 *)var_s0)->unk4 = (s32) arg2->unk4;
            }
            var_s1 -= 1;
            var_s0 += 8;
        } while (var_s1 != 0);
    }
    return var_s0;
}
