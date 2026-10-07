typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0x2C];
    s32 unk30;
};

extern "C" void func_00105510(Obj *arg0, s32 arg1) {
    arg0->unk30 = (arg0->unk0 < 0) ? 0 : arg1;
}
