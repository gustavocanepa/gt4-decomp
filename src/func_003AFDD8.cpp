typedef int s32;
typedef float f32;

extern s32 D_006184F0;

extern "C" f32 func_003AFDD8(s32 flags) {
    f32 v;
    if (!(flags & 4))
        return 0.0f;
    v = 96.0f;
    if (D_006184F0 == 0)
        v = 0.0f;
    if (flags & 8)
        return v;
    return -v;
}
