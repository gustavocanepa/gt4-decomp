typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline f32 clampf(const f32 &v, f32 lo, f32 hi) { return minf(maxf(v, lo), hi); }

extern "C" f32 func_0040F778(f32 x) {
    f32 t = clampf(x, 0.0f, 1.0f);
    t = (t - 0.5f) * 2.0f;
    return (1.0f - t * t) * 0x1.333332p-4f;
}
