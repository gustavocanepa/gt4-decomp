typedef int s32;

struct Obj {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
};

extern "C" void func_002841B0(Obj *arg0, s32 arg1) {
    arg0->unk2C = arg1;
    arg0->unk30 = 0;
}
