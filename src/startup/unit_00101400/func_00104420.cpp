extern "C" void func_00104258(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00659D50;

extern "C" void func_00104420(void *arg0, int arg1) {
    *(void **)arg0 = &D_00659D50;
    func_00104258(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
