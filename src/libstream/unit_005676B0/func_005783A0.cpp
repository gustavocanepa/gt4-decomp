typedef int s32;

extern "C" void func_00577F80();
extern "C" s32 func_00578290();
extern "C" s32 func_005ADCB0(s32 arg0);

extern "C" void func_005783A0(void) {
    s32 s0 = func_00578290();
    if (s0 != -1) {
        while (func_005ADCB0(s0) == -1) {
            func_00577F80();
        }
    }
}
