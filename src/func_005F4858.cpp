extern "C" void func_003DEEA0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006798C0;

extern "C" void func_005F4858(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0xC) = &D_006798C0;
    func_003DEEA0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
