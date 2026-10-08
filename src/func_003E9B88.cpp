typedef int s32;

extern "C" void func_003E9BF0(void *arg0);
extern "C" void *func_005C1498(s32 arg0);

extern "C" void *func_003E9B88(void) {
    void *s0 = func_005C1498(0xF140);
    func_003E9BF0(s0);
    return s0;
}
