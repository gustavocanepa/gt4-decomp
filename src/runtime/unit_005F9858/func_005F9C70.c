/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005F9C70_temp_a0 {
    char pad0[0x18];
    f32 unk18;
    f32 unk1C;
};

void func_005F9C70(s32 arg0, f32 fparg0, f32 fparg1) {
    struct func_005F9C70_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x3C;
    temp_a0->unk18 = fparg0;
    temp_a0->unk1C = fparg1;
}
