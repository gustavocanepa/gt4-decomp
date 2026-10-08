typedef int s32;

extern "C" void *func_005C1498(s32 size);
extern "C" void func_0038A660(void *arg0);

extern "C" void *func_0038A5F8(void) {
    void *v0 = func_005C1498(0xE440);

    func_0038A660(v0);
    return v0;
}
