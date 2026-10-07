extern "C" void func_0020FCE0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0066CF80;

extern "C" void func_005E7150(void *arg0, int arg1) {
    *(void **)arg0 = &D_0066CF80;
    func_0020FCE0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
