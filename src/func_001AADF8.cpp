typedef int s32;

extern "C" void func_002638E0(void *, s32, s32);
extern "C" void func_001AB4C0(void *, s32);

extern "C" void func_001AADF8(void *arg0, s32 arg1) {
    func_002638E0(arg0, arg1, 0);
    func_001AB4C0(arg0, arg1);
}
