/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005EAA20_temp_a0 {
    char pad0[0x30];
    f32 unk30;
    char pad34[0x4];
    f32 unk38;
};

void func_005EAA20(s32 arg0, f32 fparg0) {
    struct func_005EAA20_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xC0;
    temp_a0->unk30 = fparg0;
    temp_a0->unk38 = fparg0;
}
