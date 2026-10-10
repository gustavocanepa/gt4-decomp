#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0013BD50(void *, void *);              /* extern */

struct func_005C6800_var_s0 {
    char pad0[0x4];
    f32 unk4;
};
struct func_005C6800_var_s1 {
    char pad0[0x4];
    f32 unk4;
};

void *func_005C6800(void *arg0, s32 arg1, void *arg2) {
    void *var_s0;
    void *var_s1;

    var_s1 = arg0;
    var_s0 = arg2;
    if (var_s1 != arg1) {
        do {
            if (var_s0 != NULL) {
                func_0013BD50(var_s0, var_s1);
                ((struct func_005C6800_var_s0 *)var_s0)->unk4 = (f32) ((struct func_005C6800_var_s1 *)var_s1)->unk4;
            }
            var_s1 += 8;
            var_s0 += 8;
        } while (var_s1 != arg1);
    }
    return var_s0;
}
