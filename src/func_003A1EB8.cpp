typedef int s32;

struct Obj {
    char pad0[0x60];
    s32 unk60;
};

extern "C" void func_003A1EB8(Obj *arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        arg0->unk60 = arg0->unk60 | arg1;
        return;
    }
    arg0->unk60 = arg0->unk60 & ~arg1;
}
