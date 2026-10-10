typedef int s32;
typedef signed char s8;

extern "C" s8 D_00620300[8];

extern "C" s8 func_0034AAD8(s8 c) {
    s32 i;
    s8 r = c;
    for (i = 0; i < 8; i++) {
        if (D_00620300[i] == c) {
            r = i;
            break;
        }
    }
    return r;
}
