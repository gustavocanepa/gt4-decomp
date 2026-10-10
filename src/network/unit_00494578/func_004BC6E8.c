/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_004BC6E8_arg0_unk40 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x11];
    s8 unk1D;
    char pad1E[0xA];
    s8 unk28;
    char pad29[0x54];
    s8 unk7D;
    char pad7E[0x72];
    s16 unkF0;
};
struct func_004BC6E8_arg0 {
    char pad0[0x40];
    struct func_004BC6E8_arg0_unk40 *unk40;
};

void func_004BC6E8(struct func_004BC6E8_arg0 *arg0) {
    arg0->unk40->unk8 = 0;
    arg0->unk40->unk1D = 0;
    arg0->unk40->unk28 = 0;
    arg0->unk40->unk7D = 0;
    arg0->unk40->unkF0 = 0;
    arg0->unk40->unk0 = 0;
    arg0->unk40->unk4 = 0;
}
