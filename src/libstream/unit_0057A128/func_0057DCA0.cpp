extern "C" void func_0057DDA8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689F50;

extern "C" void func_0057DCA0(void *arg0, int arg1) {
    *(void **)arg0 = &D_00689F50;
    func_0057DDA8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
