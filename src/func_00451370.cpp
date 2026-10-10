typedef int s32;
typedef float f32;

struct Self { char pad[0x38]; s32 dir; f32 v; };

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

extern "C" void func_00451370(Self *self, f32 dt, s32 dir) {
    f32 d = dt * 0x1.e07b02p+3f;
    f32 cur = self->v;
    f32 v;
    if (dir) v = cur + d;
    else v = cur - d;
    self->v = minf(maxf(v, 0.0f), 0x1.000000p+0f);
    self->dir = dir;
}
