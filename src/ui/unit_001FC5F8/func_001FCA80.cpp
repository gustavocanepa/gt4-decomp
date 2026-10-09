typedef int s32;

struct Obj001FCA80 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern "C" void func_001FCA80(struct Obj001FCA80 *arg0, s32 arg1) {
    arg0->unk10 = arg1;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
}
