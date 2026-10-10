typedef int s32;
typedef short s16;
typedef signed char s8;
s32 func_00539100(char *arg0, s16 arg1) {
    s32 r = 2;
    if (arg0 != 0) {
        r = 0;
        *(s8 *)(arg0 + 0) = arg1 >> 8;
        *(s8 *)(arg0 + 1) = arg1;
    }
    return r;
}
