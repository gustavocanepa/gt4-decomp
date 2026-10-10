#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FC618();                            /* extern */

struct func_003FC6D8_arg0 {
    char pad0[0x70];
    f32 unk70;
};

void func_003FC6D8(struct func_003FC6D8_arg0 *arg0, s32 arg1, f32 *arg2) {
    f32 temp_f20;

    temp_f20 = arg0->unk70;
    *arg2 = 0x1.0000000000000p+0f;
    func_003FC618();
    if (temp_f20 != 0x0.0p+0f) {
        *arg2 = (0x1.0000000000000p+1f * (0x1.0000000000000p-1f - temp_f20) * 0x1.6666660000000p-1f) + 0x1.3333320000000p-2f;
    }
}
