typedef int s32;

extern "C" void func_003B9A18(s32 arg0, s32 arg1);

extern "C" s32 func_003B99E8(s32 arg0) {
    if (arg0 != 0) {
        func_003B9A18(arg0, 0);
    }
    return arg0;
}
