typedef int s32;

extern "C" void func_00309360(s32 arg0, s32 arg1);

extern "C" s32 func_005E9CE0(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_00309360(s0, arg1 + 0xF0);
    return s0;
}
