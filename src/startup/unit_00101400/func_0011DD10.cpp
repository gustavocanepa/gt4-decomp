typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Sample {
    int time;
    short value;
    short value2;
};

struct Curve {
    Sample samples[2][0x4000];
    int counts[2];
    f32 step;
};

extern "C" f32 func_0011DBB0(const Curve *c, int track);

extern "C" f32 func_0011DD10(const Curve *c, int track, f32 t) {
    f32 x = maxf(t - c->step, 0.0f);
    x = minf(x, func_0011DBB0(c, track));
    int i = (int)(x / c->step);
    return (f32)c->samples[track][i].value2;
}
