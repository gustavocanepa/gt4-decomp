#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00526B88_arg0 {
    char pad0[0x84];
    s32 unk84;
};
struct func_00526B88_temp_v0 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_00526B88(struct func_00526B88_arg0 *arg0, s32 arg1) {
    struct func_00526B88_temp_v0 *temp_v0;

    temp_v0 = ((arg1 & 0xFFFF) * 0x44) + arg0->unk84;
    if (temp_v0->unk18 != 1) {
        temp_v0->unk18 = 1;
    }
    return 0;
}
