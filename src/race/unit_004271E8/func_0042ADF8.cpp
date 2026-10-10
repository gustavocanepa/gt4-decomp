extern "C" void func_0042C790(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00686E00;

struct func_0042ADF8_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void func_0042ADF8(struct func_0042ADF8_arg0 *arg0, int arg1) {
    arg0->unk4 = &D_00686E00;
    func_0042C790(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
