#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003844D0_arg0 {
    char pad0[0xC];
    f32 unkC;
    char pad10[0x1B0];
    f32 unk1C0;
    f32 unk1C4;
    f32 unk1C8;
    f32 unk1CC;
    f32 unk1D0;
    f32 unk1D4;
};
struct func_003844D0_arg1 {
    char pad0[0x60];
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    char pad78[0x54];
    f32 unkCC;
};

void func_003844D0(struct func_003844D0_arg0 *arg0, struct func_003844D0_arg1 *arg1) {
    arg0->unk1C0 = (f32) arg1->unk60;
    arg0->unk1C4 = (f32) arg1->unk64;
    arg0->unk1C8 = (f32) arg1->unk68;
    arg0->unk1CC = (f32) arg1->unk70;
    arg0->unk1D0 = (f32) arg1->unk6C;
    arg0->unk1D4 = (f32) arg1->unk74;
    arg0->unkC = (f32) arg1->unkCC;
}
