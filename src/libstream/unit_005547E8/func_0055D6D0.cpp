typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

struct S0055D6D0 {
    char pad0[0x14];
    s32 unk14;
    char pad1[0x1A - 0x18];
    u16 unk1A;
    char pad2[0x28 - 0x1C];
    u8 unk28;
};

extern "C" void func_0055D6D0(S0055D6D0 *arg0) {
    s32 v = arg0->unk1A;
    arg0->unk28 = 1;
    arg0->unk14 = 0;
    v |= 3;
    v -= 2;
    arg0->unk1A = (u16)v;
}
