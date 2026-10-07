extern "C" void func_004B3698(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689358;

extern "C" void func_004B1AA8(void *arg0, int arg1) {
    *(void **)arg0 = &D_00689358;
    func_004B3698(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
