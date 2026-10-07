extern "C" void func_004AF708(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_00688FA0;

extern "C" void func_004AFCE8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x20) = &D_00688FA0;
    func_004AF708(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
