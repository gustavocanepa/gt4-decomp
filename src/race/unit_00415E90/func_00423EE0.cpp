typedef float f32;
typedef int s128 __attribute__((mode(TI)));

struct Vec {
    union {
        struct {
            f32 x, y, z, w;
        } f;
        s128 q;
    };
    Vec() {}
    Vec(const Vec &o) : q(o.q) {}
    Vec &operator=(const Vec &o) { q = o.q; return *this; }
    Vec &operator*=(f32 s) { f.x *= s; f.y *= s; return *this; }
};

static inline Vec operator*(const Vec &v, f32 s) {
    Vec r(v);
    r *= s;
    return r;
}

// Dot product of a and b scales b into out. Reading a->y first makes the a.x load the last use of
// `a` (its REG_DEAD note), so sched1 loads a.y late and local-alloc ranks it before the x term.
extern "C" void func_00423EE0(Vec *out, const Vec *a, const Vec *b) {
    f32 ay = a->f.y;
    f32 d = a->f.x * b->f.x + ay * b->f.y;
    *out = *b * d;
}
