typedef float f32;

static inline f32 fabs_(f32 v) {
    f32 r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(v));
    return r;
}

extern "C" f32 func_0045C9B0(f32 x) {
    if (fabs_(x) < 0x1.f6a7a0p+5f) return x;
    return x < 0.0f ? -0x1.f6a7a0p+5f : 0x1.f6a7a0p+5f;
}
