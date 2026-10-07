extern "C" void func_003AEBF8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_0067F508;

extern "C" void func_005F8BC0(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x14) = &D_0067F508;
    func_003AEBF8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
