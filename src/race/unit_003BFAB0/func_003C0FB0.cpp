typedef float f32;

struct Obj {
    char pad[0xD8];
    f32 unkD8;
};

static inline f32 min_s(f32 a, f32 b) {
    f32 r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" f32 func_003C0F88(Obj *);

extern "C" f32 func_003C0FB0(Obj *self) {
    f32 t = func_003C0F88(self) / self->unkD8;
    return min_s(t, 1.0f);
}
