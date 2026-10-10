typedef int s32;
s32 func_005314D8(s32, s32, s32);
s32 func_00535780(s32);
s32 func_00536CF8(void);
s32 func_00536D38(void);
s32 func_0052E8A0(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = func_00535780(func_00536CF8());
    s32 a, b;
    if (r != 0) return r;
    a = func_005314D8(arg0, arg1, arg2);
    b = func_00535780(func_00536D38());
    return b ? b : a;
}
