typedef int s32;

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" void func_003C6570(Obj *arg0, s32 arg1) {
    arg0->unk4 = arg1 * 0x3C;
}
