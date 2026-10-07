typedef int s32;

struct List {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" void func_00463908(List *arg0, s32 *arg1) {
    *arg1 = arg0->unkC;
    arg0->unkC = (s32)arg1;
    arg0->unk14 = arg0->unk14 + 1;
    arg0->unk10 = arg0->unk10 - 1;
}
