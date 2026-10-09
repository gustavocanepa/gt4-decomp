typedef int s32;
typedef float f32;

extern "C" s32 func_00395CC0(void *arg0, s32 arg1, f32 *arg2);

static inline f32 gt4_sqrtf(f32 x)
{
    f32 r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" f32 func_00395DE8(void *arg0, s32 arg1)
{
    f32 sp0;
    s32 v0;
    f32 result;

    v0 = func_00395CC0(arg0, arg1, &sp0);
    result = 0.0f;
    if (v0 >= 0) {
        result = gt4_sqrtf(sp0);
    }
    return result;
}
