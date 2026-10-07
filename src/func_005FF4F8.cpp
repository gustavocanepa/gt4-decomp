extern "C" void func_003DEEA0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *D_006863E0;

extern "C" void func_005FF4F8(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0xC) = &D_006863E0;
    func_003DEEA0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
