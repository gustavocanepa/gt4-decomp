#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F6778_arg0 {
    char pad0[0xCC8];
    s32 unkCC8;
};

s32 func_005F6778(struct func_005F6778_arg0 *arg0) {
    s32 temp_v1;
    s32 var_a0;

    temp_v1 = arg0->unkCC8;
    var_a0 = 0;
    if ((temp_v1 == 0) || (temp_v1 == 2)) {
        var_a0 = 1;
    }
    return var_a0;
}
