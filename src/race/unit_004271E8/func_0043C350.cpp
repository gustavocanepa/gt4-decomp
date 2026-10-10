extern "C" void func_004383F8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006881A0;

struct func_0043C350_arg0 {
    char pad0[0xC];
    void *unkC;
};

extern "C" void func_0043C350(struct func_0043C350_arg0 *arg0, int arg1) {
    arg0->unkC = &D_006881A0;
    func_004383F8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
