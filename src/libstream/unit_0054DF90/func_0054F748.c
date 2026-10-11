#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void *func_00578CB0(s32);                       /* extern */
s32 func_00578CF0(s32, s32);                /* extern */

struct func_0054F748_temp_s0 {
    char pad0[0x4];
    s32 unk4;
    void *unk8;
    void *unkC;
};

void *func_0054F748(void) {
    struct func_0054F748_temp_s0 *temp_s0;

    temp_s0 = func_00578CB0(0x24);
    temp_s0->unk4 = func_00578CF0(0x10, 0x2000);
    temp_s0->unk8 = func_00578CB0(0x44);
    temp_s0->unkC = func_00578CB0(0x2C);
    return temp_s0;
}
