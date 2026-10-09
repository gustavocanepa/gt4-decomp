typedef int s32;

struct S0042AB30 {
    s32 unk0;
    void *unk4;
    char pad8[0x14 - 0x8];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

extern "C" char D_00686CE0[];

extern "C" void func_0042AB30(struct S0042AB30 *arg0, s32 arg1, s32 arg2) {
    arg0->unk14 = arg1;
    arg0->unk18 = arg2;
    arg0->unk4 = D_00686CE0;
    arg0->unk0 = 0;
    arg0->unk1C = 0;
}
