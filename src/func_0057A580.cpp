typedef int s32;
typedef signed char s8;

extern "C" void func_0057A580(s8 **arg0, s32 arg1, s32 arg2) {
    s8 *p;

    p = *arg0 + arg1;
    arg2 += *p;
    *p = (s8)arg2;
}
