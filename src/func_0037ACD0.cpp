typedef int s32;

extern s32 D_006211E8[];

extern "C" s32 func_0037ACD0(s32 x) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (D_006211E8[i] == x) return i;
    }
    return -1;
}
