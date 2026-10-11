#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003CAFE0_arg0 {
    char pad0[0x14];
    f32 unk14;
    s32 unk18;
};

void func_003CAFE0(struct func_003CAFE0_arg0 *arg0) {
    f32 temp_f0;

    if (arg0->unk18 == 0) {
        temp_f0 = arg0->unk14 + 0x1.9999980000000p-4f;
        arg0->unk18 = 1;
        arg0->unk14 = temp_f0;
        if (temp_f0 > 0x1.0000000000000p+0f) {
            arg0->unk14 = 0x1.0000000000000p+0f;
        }
    }
}
