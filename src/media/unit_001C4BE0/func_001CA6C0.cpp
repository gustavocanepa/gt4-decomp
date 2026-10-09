typedef int s32;

struct Obj {
    char pad[0x54];
    s32 unk54;
};

extern "C" void func_005C1D10(void);

extern "C" void func_001CA6C0(Obj *arg0) {
    if (arg0->unk54 != 0) {
        func_005C1D10();
        arg0->unk54 = 0;
    }
}
