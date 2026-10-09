typedef float f32;
typedef int s32;

extern "C" s32 func_0049B330(f32 *lo, f32 *hi);

extern "C" s32 func_003D0B70(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 lo[3];
    f32 hi[3];
    s32 v0;

    lo[1] = fparg1 - 2.0f;
    lo[0] = fparg0 - 2.0f;
    lo[2] = fparg2 - 2.0f;
    hi[0] = fparg0 + 2.0f;
    hi[1] = fparg1 + 2.0f;
    hi[2] = fparg2 + 2.0f;
    v0 = func_0049B330(lo, hi);
    return v0 != 0;
}
