extern "C" void func_00372600(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006827E0;

extern "C" void func_005FD938(void *arg0, int arg1) {
    *(void **)arg0 = &D_006827E0;
    func_00372600(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
