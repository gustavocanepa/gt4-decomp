/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005E7830_temp_a0 {
    char pad0[0x2C];
    f32 unk2C;
    char pad30[0x4];
    f32 unk34;
};

void func_005E7830(s32 arg0, f32 fparg0) {
    struct func_005E7830_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xA0;
    temp_a0->unk2C = fparg0;
    temp_a0->unk34 = fparg0;
}
