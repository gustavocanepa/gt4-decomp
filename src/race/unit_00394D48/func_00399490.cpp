typedef float f32;

struct Struct_00399490 {
    f32 unk0;
    f32 unk4;
};

static inline f32 rsqrt_s(f32 a, f32 b) {
    f32 r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" void func_00399490(struct Struct_00399490 *arg0, f32 fparg0, f32 fparg1) {
    f32 t = fparg1 * fparg1;
    f32 u = fparg0 * 0.001f;
    arg0->unk0 = fparg0;
    t = t + 1.0f;
    arg0->unk4 = rsqrt_s(u, t);
}
