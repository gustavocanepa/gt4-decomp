typedef int s32;

extern "C" void func_002FF9D0(s32 arg0, void *arg1);

extern "C" void func_0031C8F0(void *arg0, s32 arg1) {
    func_002FF9D0(arg1, (char *)arg0 + 8);
}
