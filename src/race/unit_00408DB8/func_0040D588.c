#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0040D588_arg0 {
    char pad0[0xF8];
    f32 unkF8;
};

s32 func_0040D588(struct func_0040D588_arg0 *arg0) {
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = arg0->unkF8;
    var_v0 = 0;
    if ((temp_f1 > -0x1.1c71c60000000p-3f) && (temp_f1 < 0x1.1c71c60000000p-3f)) {
        var_v0 = 1;
    }
    return var_v0;
}
