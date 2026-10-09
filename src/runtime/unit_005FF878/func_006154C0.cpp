typedef int s32;

extern "C" void func_006154C0(s32 *arg0, s32 arg1, s32 arg2) {
    *arg0 = (*arg0 & ~arg2) | (arg1 & arg2);
}
