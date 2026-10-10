typedef int s32;
void func_005A48D8(s32 a, s32 b, s32 c);
void func_00332740(s32 a, s32 b, s32 c);
void func_00332A20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_005A48D8(arg2, 0, arg3);
    while (arg1 > 0) {
        s32 n = arg3 < arg1 ? arg3 : arg1;
        arg1 -= arg3;
        func_00332740(arg0, arg2, n);
    }
}
