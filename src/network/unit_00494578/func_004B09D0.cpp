extern "C" void func_004AD240(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689050;

struct func_004B09D0_arg0 {
    char pad0[0xA4];
    void *unkA4;
};

extern "C" void func_004B09D0(struct func_004B09D0_arg0 *arg0, int arg1) {
    arg0->unkA4 = &D_00689050;
    func_004AD240(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
