extern "C" void func_004B09D0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689178;

struct func_004B1670_arg0 {
    char pad0[0xA4];
    void *unkA4;
};

extern "C" void func_004B1670(struct func_004B1670_arg0 *arg0, int arg1) {
    arg0->unkA4 = &D_00689178;
    func_004B09D0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
