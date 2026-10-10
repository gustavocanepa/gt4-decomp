#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005F67A0_arg0 {
    char pad0[0xCC8];
    s32 unkCC8;
};

s32 func_005F67A0(struct func_005F67A0_arg0 *arg0) {
    s32 temp_v1;
    s32 var_a0;

    temp_v1 = arg0->unkCC8;
    var_a0 = 0;
    if ((temp_v1 == 1) || (temp_v1 == 3)) {
        var_a0 = 1;
    }
    return var_a0;
}
