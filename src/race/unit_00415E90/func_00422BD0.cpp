typedef float f32;

extern "C" f32 func_0057D6C0(f32 x, f32 y); /* powf */

static inline f32 absf(f32 v) {
    f32 r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

extern "C" f32 func_00422BD0(f32 x) {
    f32 r = func_0057D6C0(absf(x), 0x1.555554p-2f);
    f32 s;
    if (x > 0.0f)
        s = 1.0f;
    else
        s = -1.0f;
    return r * s;
}
