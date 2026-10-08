typedef int s32;

struct S8 {
    char data[8];
};

struct Obj {
    s32 unk0;
    S8 unk4;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad1C[4];
    s32 unk20;
};

extern "C" void func_003C8F60(Obj *arg0, S8 *arg1) {
    arg0->unk0 = 0;
    arg0->unk4 = *arg1;
    arg0->unk20 = 0;
    arg0->unkC = 0;
    arg0->unk10 = -1;
    arg0->unk14 = -1;
    arg0->unk18 = -1;
}
