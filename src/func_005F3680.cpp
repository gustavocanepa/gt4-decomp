extern "C" void func_0044F198(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006884A8;

extern "C" void func_005F3680(void *arg0, int arg1) {
    *(void **)arg0 = &D_006884A8;
    func_0044F198(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
