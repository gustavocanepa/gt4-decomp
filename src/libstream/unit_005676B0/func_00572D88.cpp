typedef int s32;

struct Obj {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
};

extern "C" void func_00572D88(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unkC = arg1;
    arg0->unk10 = arg1 + arg2;
}
