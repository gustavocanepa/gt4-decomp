extern "C" void func_0020FCE0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00666D20;

extern "C" void func_005DCFC8(void *arg0, int arg1) {
    *(void **)arg0 = &D_00666D20;
    func_0020FCE0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
