extern "C" void func_0033B840(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006839C8;

extern "C" void func_003E9940(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x20) = &D_006839C8;
    func_0033B840(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
