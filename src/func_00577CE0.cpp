extern "C" void func_00577E38(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00689E00;

extern "C" void func_00577CE0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &D_00689E00;
    func_00577E38(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
