#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004462E0(void *);
s32 func_00446320(void *);
struct func_00441B20_arg1 {
    char pad0[0x2];
    u8 unk2;
    char pad3[0xD];
    u16 unk10;
    char pad12[0x8];
    u16 unk1A;
    char pad1C[0x4];
    u16 unk20;
    u8 unk22;
    char pad23[0x1];
    u8 unk24;
    char pad25[0x2];
    u8 unk27;
    char pad28[0x2];
    s8 unk2A;
    s8 unk2B;
    char pad2C[0x4];
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    s8 unk38;
    s8 unk39;
    u16 unk3A;
    char pad3C[0x1A6];
    u8 unk1E2;
    u8 unk1E3;
    u8 unk1E4;
    u8 unk1E5;
};
struct func_00441B20_arg2 {
    u16 unk0;
    char pad2[0x2];
    u16 unk4;
    u16 unk6;
    char pad8[0x6];
    u8 unkE;
    char padF[0x1];
    u8 unk10;
    char pad11[0x1];
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    char pad1A[0x2];
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
};
struct func_00441B20_arg0 {
    char pad0[0x168];
    u8 unk168;
};

void func_00441B20(struct func_00441B20_arg0 *arg0, struct func_00441B20_arg1 *arg1, struct func_00441B20_arg2 *arg2) {
    arg1->unk22 = (u8) arg2->unk1C;
    arg1->unk2A = (s8) (arg2->unkE + 0x7C);
    arg1->unk2B = (s8) (arg2->unk10 + 0x7C);
    arg1->unk1A = (u16) arg2->unk4;
    arg1->unk20 = (u16) arg2->unk6;
    arg1->unk24 = (u8) arg2->unk1D;
    arg1->unk27 = (u8) arg2->unk1E;
    arg1->unk10 = (u16) arg2->unk0;
    arg1->unk1A = (u16) arg2->unk4;
    arg1->unk20 = (u16) arg2->unk6;
    arg1->unk3A = (u16) arg2->unk6;
    arg1->unk27 = (u8) arg2->unk1E;
    arg1->unk10 = (u16) arg2->unk0;
    arg1->unk2 = (u8) arg2->unk1F;
    arg1->unk30 = (u16) arg2->unk12;
    arg1->unk32 = (u16) arg2->unk14;
    arg1->unk34 = (u16) arg2->unk16;
    arg1->unk36 = (u16) arg2->unk18;
    arg1->unk38 = (s8) (arg2->unk22 + arg0->unk168);
    arg1->unk39 = (s8) (arg2->unk23 + arg0->unk168);
    if ((u32) (func_004462E0(arg0) - 6) < 5U) {
        arg1->unk1E2 = (u8) arg2->unk20;
        arg1->unk1E4 = (u8) arg2->unk21;
    }
    if ((u32) (func_00446320(arg0) - 6) < 5U) {
        arg1->unk1E3 = (u8) arg2->unk20;
        arg1->unk1E5 = (u8) arg2->unk21;
    }
}
