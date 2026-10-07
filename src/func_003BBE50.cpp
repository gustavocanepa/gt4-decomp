extern "C" void func_0033D000(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00680CA8;

extern "C" void func_003BBE50(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &D_00680CA8;
    func_0033D000(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
