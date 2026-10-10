typedef short s16;
typedef int s32;
s16 func_004B9210(s32 a);
s32 func_004B9300(s16 *arg0, s32 arg1) {
    s16 v = func_004B9210(arg1);
    if (v == 0) return 0;
    arg0[0] = v;
    arg0[1] = 0;
    return 1;
}
