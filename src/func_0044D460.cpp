extern "C" void func_004AFCE8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006883D8;

extern "C" void func_0044D460(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x20) = &D_006883D8;
    func_004AFCE8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
