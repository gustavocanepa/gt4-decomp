typedef int s32;

struct Obj {
    char pad[0x4];
    s32 unk4;
    char pad2[0x4];
    s32 unkC;
    s32 unk10;
};

extern "C" void func_003FF770(Obj *arg0) {
    arg0->unk10 = 0;
    arg0->unkC = 2;
    arg0->unk4 = 0;
}
