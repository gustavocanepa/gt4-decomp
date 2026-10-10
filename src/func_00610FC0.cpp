extern "C" void func_00556450(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689970;

struct func_00610FC0_arg0 {
    char pad0[0x60];
    void *unk60;
};

extern "C" void func_00610FC0(struct func_00610FC0_arg0 *arg0, int arg1) {
    arg0->unk60 = &D_00689970;
    func_00556450(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
