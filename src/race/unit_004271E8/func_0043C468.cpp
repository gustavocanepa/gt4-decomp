extern "C" void func_0043C350(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00688130;

struct func_0043C468_arg0 {
    char pad0[0xC];
    void *unkC;
};

extern "C" void func_0043C468(struct func_0043C468_arg0 *arg0, int arg1) {
    arg0->unkC = &D_00688130;
    func_0043C350(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
