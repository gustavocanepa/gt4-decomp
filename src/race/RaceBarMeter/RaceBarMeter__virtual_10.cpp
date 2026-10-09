typedef float f32;

struct Obj {
    char pad0[0x18];
    f32 unk18;
    char pad1C[4];
    f32 unk20;
};

static inline f32 min_s(f32 a, f32 b) {
    f32 r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

extern "C" f32 RaceBarMeter__virtual_10(Obj *arg0) {
    f32 r = arg0->unk18 / arg0->unk20;
    return min_s(r, 1.0f);
}
