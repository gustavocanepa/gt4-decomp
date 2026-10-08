typedef int s32;

extern "C" void func_003E9908(void *arg0);
extern "C" void *func_005C1498(s32 arg0);

extern "C" void *func_003E9AB8(void) {
    void *s0 = func_005C1498(0x5C);
    func_003E9908(s0);
    return s0;
}
