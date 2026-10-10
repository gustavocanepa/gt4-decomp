#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0057B130_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_0057B130(void *arg0) {
    s32 *var_a0;
    s32 var_v1;

    var_v1 = 0;
    if (((struct func_0057B130_arg0 *)arg0)->unk4 != 0) {
        var_a0 = arg0 + 4;
        do {
            var_a0 += 2;
            var_v1 += 1;
        } while (*var_a0 != 0);
    }
    return var_v1;
}
