#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00442800_arg1 {
    char pad0[0x1C];
    u16 unk1C;
    u16 unk1E;
    s16 unk20;
    char pad22[0x2];
    u8 unk24;
    char pad25[0x1D];
    u8 unk42;
    u8 unk43;
    u8 unk44;
    char pad45[0x7];
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    u8 unk4F;
    u8 unk50;
    char pad51[0x45];
    u8 unk96;
    u8 unk97;
    u8 unk98;
    u8 unk99;
};
struct func_00442800_arg2 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    char pad6[0x6];
    u8 unkC;
    char padD[0x6];
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
};
struct func_00442800_arg0 {
    char pad0[0x131];
    u8 unk131;
    u8 unk132;
};

void func_00442800(struct func_00442800_arg0 *arg0, struct func_00442800_arg1 *arg1, struct func_00442800_arg2 *arg2) {
    arg1->unk20 = (s16) ((s32) (arg1->unk20 * arg2->unk0) / 1000);
    arg1->unk24 = (u8) ((s32) (arg1->unk24 * arg2->unk17) / 100);
    arg1->unk42 = (u8) arg2->unkC;
    arg1->unk1C = (u16) arg2->unk2;
    arg1->unk1E = (u16) arg2->unk4;
    arg1->unk43 = (u8) arg0->unk131;
    arg1->unk44 = (u8) arg0->unk132;
    arg1->unk96 = (u8) arg2->unk13;
    arg1->unk97 = (u8) arg2->unk14;
    arg1->unk98 = (u8) arg2->unk15;
    arg1->unk99 = (u8) arg2->unk16;
    arg1->unk4C = (u8) arg2->unk18;
    arg1->unk4D = (u8) arg2->unk19;
    arg1->unk4E = (u8) arg2->unk1A;
    arg1->unk4F = (u8) arg2->unk1B;
    arg1->unk50 = (u8) arg2->unk1C;
}
