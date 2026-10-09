typedef int s32;

struct Obj {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

extern "C" void func_001057F8(Obj *arg0) {
    arg0->unk18 = arg0->unk8;
    arg0->unk1C = arg0->unkC;
    arg0->unk14 = 0;
    arg0->unk10 = 0;
}
