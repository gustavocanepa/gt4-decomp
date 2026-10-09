typedef int s32;

extern "C" void func_003041A0(s32 arg0, s32 arg1);

extern "C" s32 func_002EC370(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_003041A0(s0, arg1 + 0x38);
    return s0;
}
