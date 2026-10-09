typedef int s32;

struct Obj {
    s32 unk0;
    char pad4[0x40 - 0x4];
    s32 unk40;
};

extern "C" void func_001C60B0(Obj *arg0) {
    s32 v = arg0->unk0;
    if (v < 3) {
        if (v >= 0) {
            arg0->unk40 = 0;
            arg0->unk0 = 3;
        }
    }
}
