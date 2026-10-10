typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

extern "C" f32 func_003DBE98(f32 x) {
    f32 t = (x - 20.0f) * 0.0125f;
    t = minf(maxf(t, 0.0f), 1.0f);
    return t * 38.0f + 62.0f;
}
