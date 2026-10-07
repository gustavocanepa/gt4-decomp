typedef int s32;

struct Obj {
    s32 unk0;
    char pad4[0xC];
    s32 unk10;
    s32 unk14;
};

extern "C" void func_0055A1D0(Obj *arg0, s32 arg1) {
    if (arg0->unk0 == arg1) {
        arg0->unk0 = 0;
        if (arg0->unk10 != 0) {
            arg0->unk14 = 0;
        }
    }
}
