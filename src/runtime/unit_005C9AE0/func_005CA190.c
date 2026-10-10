/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0021B328(void *, void *);              /* extern */

struct func_005CA190_var_s0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
};
struct func_005CA190_var_s1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
};

void *func_005CA190(void *arg0, s32 arg1, void *arg2) {
    void *var_s0;
    void *var_s1;

    var_s1 = arg0;
    var_s0 = arg2;
    if (var_s1 != arg1) {
        do {
            if (var_s0 != NULL) {
                func_0021B328(var_s0, var_s1);
                ((struct func_005CA190_var_s0 *)var_s0)->unk4 = (s32) ((struct func_005CA190_var_s1 *)var_s1)->unk4;
                ((struct func_005CA190_var_s0 *)var_s0)->unk8 = (s32) ((struct func_005CA190_var_s1 *)var_s1)->unk8;
                ((struct func_005CA190_var_s0 *)var_s0)->unkC = (s32) ((struct func_005CA190_var_s1 *)var_s1)->unkC;
                ((struct func_005CA190_var_s0 *)var_s0)->unk10 = (f32) ((struct func_005CA190_var_s1 *)var_s1)->unk10;
            }
            var_s1 += 0x14;
            var_s0 += 0x14;
        } while (var_s1 != arg1);
    }
    return var_s0;
}
