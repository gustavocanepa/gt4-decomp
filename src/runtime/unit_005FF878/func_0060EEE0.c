#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0060EEE0_arg0 {
    char pad0[0x164];
    s32 unk164;
};

s32 func_0060EEE0(struct func_0060EEE0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk164;
    arg0->unk164 = 0;
    return temp_v0;
}
