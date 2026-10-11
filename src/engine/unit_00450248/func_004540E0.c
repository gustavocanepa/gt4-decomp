#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004540E0_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    char pad20[0x4];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};

void func_004540E0(struct func_004540E0_arg0 *arg0) {
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0x1.0000000000000p+0f;
    arg0->unk24 = 0;
    arg0->unk1C = 0x1.0000000000000p+0f;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
}
