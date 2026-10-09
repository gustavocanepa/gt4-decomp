typedef float f32;

struct Obj {
    char pad[0x6C];
    f32 unk6C;
};

static inline f32 min_s(f32 a, f32 b) {
    f32 r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" void func_003A2270(struct Obj *arg0, f32 fparg0) {
    f32 t = fparg0 * 0.3f;
    t = min_s(t, 12.0f);
    arg0->unk6C = fparg0 - t;
}
