typedef int (*FnPtr)();

extern "C" int func_005BFC20(int a0, int a1, int a2, int a3, int t0, int t1);

extern "C" int func_005C0FC8(FnPtr arg0, FnPtr arg1, int arg2, int arg3, FnPtr arg4, int arg5) {
    int s0 = arg0();
    int s1 = arg1();
    int t0result = arg4();
    return func_005BFC20(s0, arg2, s1, arg3, t0result, arg5);
}
