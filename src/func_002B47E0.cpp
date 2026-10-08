typedef int s32;

extern "C" void func_002F9B20(s32 arg0, s32 arg1);

extern "C" s32 func_002B47E0(s32 arg0, s32 arg1) {
    s32 s0 = arg0;

    func_002F9B20(arg0, arg1 + 0x114);
    return s0;
}
