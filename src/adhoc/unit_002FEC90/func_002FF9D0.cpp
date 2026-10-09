typedef signed int s32;

extern "C" s32 func_002FF870();

extern "C" s32 func_002FF9D0(s32 arg0, s32 *arg1) {
    s32 *s0 = arg1;
    s32 s1 = arg0;
    *s0 = func_002FF870();
    return s1;
}
