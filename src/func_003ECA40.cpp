typedef float f32;

static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Obj {
    char pad0[0x18];
    f32 value;
    f32 pad1C;
    f32 max;
};

extern "C" f32 func_003ECA40(Obj *self) {
    f32 ratio = minf(self->value * 0x1.666666p-1f / self->max, 1.0f);
    return (f32)(int)(ratio * 40.0f) / 40.0f;
}
