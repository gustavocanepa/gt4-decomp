extern "C" void func_0043C350(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006880C0;

extern "C" void func_0043C700(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0xC) = &D_006880C0;
    func_0043C350(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
