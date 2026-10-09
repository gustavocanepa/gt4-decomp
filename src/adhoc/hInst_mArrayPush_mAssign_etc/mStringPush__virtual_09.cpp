typedef int s32;

extern "C" void func_002FF998(s32 arg0, void *arg1);

extern "C" void mStringPush__virtual_09(void *arg0, s32 arg1) {
    func_002FF998(arg1, (char *)arg0 + 8);
}
