typedef int s32;
s32 func_00520EB0(s32 a, s32 b, s32 c, s32 *d);
s32 func_00271D10(char *arg0, s32 arg1, s32 arg2) {
    s32 out = 0;
    s32 r = func_00520EB0(*(s32 *)(arg0 + 0x10), arg1, arg2, &out);
    *(s32 *)(arg0 + 0x20) = r;
    return r == 0;
}
