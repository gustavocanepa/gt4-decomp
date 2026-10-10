extern "C" void func_00101078(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00659E80;

struct func_00108FE0_arg0 {
    char pad0[0x64];
    void *unk64;
};

extern "C" void func_00108FE0(struct func_00108FE0_arg0 *arg0, int arg1) {
    arg0->unk64 = &D_00659E80;
    func_00101078(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
