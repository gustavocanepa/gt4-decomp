typedef int s32;
typedef signed char s8;

extern s8 D_00620890[];

extern "C" s32 func_0035C828(s32 x);

extern "C" s32 func_0035C938(s32 x) {
    s32 i = func_0035C828(x);
    s8 c = D_00620890[i];
    if (c == 1 || c == -1) {
        return c;
    }
    return 0;
}
