/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int (*FnPtr)();

extern "C" int func_005BFC20(int a0, int a1, int a2, int a3, int t0, int t1);

extern "C" int func_005C0FC8(FnPtr arg0, FnPtr arg1, int arg2, int arg3, FnPtr arg4, int arg5) {
    int s0 = arg0();
    int s1 = arg1();
    int t0result = arg4();
    return func_005BFC20(s0, arg2, s1, arg3, t0result, arg5);
}
