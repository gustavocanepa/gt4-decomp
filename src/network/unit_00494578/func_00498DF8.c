/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00498DF8_arg0 {
    char pad0[0x6];
    u16 unk6;
    char pad8[0x4];
    f32 *unkC;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    f32 unk18;
    s16 unk1C;
    s8 unk1E;
};

void func_00498DF8(struct func_00498DF8_arg0 *arg0) {
    arg0->unk14 = 0x0.0p+0f;
    arg0->unk12 = (s16) (arg0->unk6 != 0);
    arg0->unk18 = 0x1.0000000000000p+0f;
    arg0->unk1E = 1;
    arg0->unk1C = 0;
    arg0->unk10 = 0;
    if (*arg0->unkC < arg0->unk14) {
        arg0->unk1C = 1;
    }
}
