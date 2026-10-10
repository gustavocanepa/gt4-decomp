#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0044BFA8_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_0044BFA8(struct func_0044BFA8_arg0 *arg0) {
    s32 var_a1;
    s32 var_v1;
    u8 *temp_v0;

    var_a1 = arg0->unk4 - 1;
    var_v1 = 0;
    if (var_a1 >= 0) {
        do {
            temp_v0 = arg0->unk0 + var_a1;
            var_a1 -= 1;
            var_v1 = (var_v1 << 8) | *temp_v0;
        } while (var_a1 >= 0);
    }
    return var_v1;
}
