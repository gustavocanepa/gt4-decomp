typedef int s32;

extern s32 D_00620204;

extern "C" s32 func_00427660(s32 arg0) {
    s32 mask = 1 << arg0;
    s32 v = D_00620204;
    return (v & mask) != 0;
}
