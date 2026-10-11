#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FD7F0_arg0 {
    char pad0[0x1E648];
    f32 unk1E648;
};

s32 func_005FD7F0(struct func_005FD7F0_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk1E648 < 1.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
