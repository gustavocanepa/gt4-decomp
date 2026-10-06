extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_005C1628(void *arg0);

extern "C" void func_001AA0A0(void *arg0, int arg1) {
    func_002550B8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
