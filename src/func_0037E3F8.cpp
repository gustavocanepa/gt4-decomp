typedef int s32;

struct Obj {
    char pad0[0x148];
    s32 unk148;
    char pad1[0x1B0 - 0x148 - 4];
    s32 unk1B0;
};

extern "C" void func_0037DBF8(struct Obj *arg0);

extern "C" void func_0037E3F8(struct Obj *arg0) {
    func_0037DBF8(arg0);
    arg0->unk1B0 = 1;
    arg0->unk148 = 8;
}
