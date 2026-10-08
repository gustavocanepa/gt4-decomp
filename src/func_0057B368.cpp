typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" void func_0057B368(struct Obj *arg0) {
    arg0->unk10 = 1;
    arg0->unkC = 0;
    arg0->unk14 = 0;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}
