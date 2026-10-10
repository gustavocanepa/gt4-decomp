#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00427820(void *);                      /* extern */
s32 func_00427830(void *, s32, s32);        /* extern */
f32 func_0042A100(void *, s32);                     /* extern */

struct func_003EBA08_arg0 {
    char pad0[0xD0];
    s32 unkD0;
};

f32 func_003EBA08(struct func_003EBA08_arg0 *arg0, s32 arg1) {
    s8 sp[0x10];
    f32 var_f0;

    var_f0 = 0.0f;
    if (arg0->unkD0 != 0) {
        func_00427820(sp);
        func_00427830(sp, 0, arg0->unkD0);
        var_f0 = func_0042A100(sp, arg1);
    }
    return var_f0;
}
