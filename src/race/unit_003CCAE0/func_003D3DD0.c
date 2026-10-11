#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003D3DD0_arg0 {
    char pad0[0x68];
    f32 unk68;
};

s32 func_003D3DD0(struct func_003D3DD0_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;

    temp_f0 = arg0->unk68 + fparg0;
    arg0->unk68 = temp_f0;
    if (temp_f0 >= 1.0f) {
        arg0->unk68 = 1.0f;
        return 1;
    }
    return 0;
}
