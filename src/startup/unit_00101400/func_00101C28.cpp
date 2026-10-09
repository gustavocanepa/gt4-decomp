typedef int s32;

extern "C" void func_0058B268(s32 arg0);

extern "C" void func_00101C28(s32 (*arg0)(void)) {
    func_0058B268(arg0());
}
