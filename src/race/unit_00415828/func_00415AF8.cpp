/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Inferred: scales the object's direction vector by how well a heading matches a target.
 * func_00414E78 gives the object's current point on its curve; func_00415828 turns the
 * origin, the direction and that point into a planar pair, and func_00415978 turns that
 * pair into two angles (0 when either step fails). The heading error x - angle (wrapped
 * by func_00420F00) is mapped linearly so that 0.8 * limit gives 0 and 1.2 * limit gives
 * 1, clamped to [0, 1] and multiplied by the weight func_00415A68 computes from y. The
 * scaled direction goes to *out and the function returns 1. */
typedef unsigned int u128 __attribute__((mode(TI)));

struct __attribute__((aligned(16))) Vec {
    union { u128 bits; struct { float x, y, z, w; }; };
    Vec() {}
    Vec(const Vec &v) { bits = v.bits; }
    void multiply(float f) { x *= f; y *= f; z *= f; }
    Vec operator*(float f) const { Vec v(*this); v.multiply(f); return v; }
    Vec &operator=(const Vec &v) { bits = v.bits; return *this; }
    float &operator[](int i) { return *(float *)((char *)this + i * 4); }
};

struct Mover {
    char pad0[0x50];
    Vec origin;
    char pad60[0x50];
    Vec direction;
    char padC0[0x20];
    float height;
};

struct __attribute__((aligned(16))) Pair {
    float x, y;
    Pair() {}
    Pair(const Pair &p) : x(p.x), y(p.y) {}
};

extern "C" float func_00420F00(float *, float);

struct __attribute__((aligned(16))) Angle {
    float v;
    Angle(float a) : v(a) {}
    Angle(const Angle &a) : v(a.v) {}
    float wrap() { return v = func_00420F00(&v, -0x1.921fb4p+1f); }
};

/* Maps [x0, x1] onto [y0, y1]. */
struct __attribute__((aligned(16))) LinearMap {
    float k, c;
    LinearMap(float x0, float x1, float y0, float y1) {
        float inv = 1.0f / (x1 - x0);
        k = inv * (y1 - y0);
        c = inv * (x1 * y0 - x0 * y1);
    }
    LinearMap(const LinearMap &m) : k(m.k), c(m.c) {}
    float operator()(float x) const { return k * x + c; }
};

struct __attribute__((aligned(16))) Range {
    float lo, hi;
};

static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float fabsf_(float a) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(a)); return r; }
static inline float clampf(float v, const float &lo, const float &hi) { return minf(maxf(v, lo), hi); }

extern "C" Vec func_00414E78(Mover *);
extern "C" int func_00415828(float *, float *, float, float, float, float, float, float, float, float, float);
extern "C" int func_00415978(float *, float *, float, float, float);
extern "C" float func_00415A68(float, float, float);

extern "C" int func_00415AF8(Vec *out, Mover *m, float heading, float t) {
    Pair planar;
    Vec &origin = m->origin;
    Vec point = func_00414E78(m);
    if (!func_00415828(&planar.x, &planar.y, origin[0], m->origin.y, m->origin.z,
                       m->direction[0], m->direction.y, m->direction.z, point[0], point.y, point.z))
        return 0;
    Pair angles;
    if (!func_00415978(&angles.x, &angles.y, m->height, planar.x, planar.y))
        return 0;
    Angle error(heading - angles.x);
    float off = fabsf_(error.wrap());
    float lo = 0.0f, hi = 1.0f;
    LinearMap ramp(angles.y * 0x1.999998p-1f, angles.y * 0x1.333332p+0f, lo, hi);
    float weight = func_00415A68(t, 0.5f, 0x1.999998p-4f);
    Range range = { lo, hi };
    *out = m->direction * (clampf(ramp(off), range.lo, range.hi) * weight);
    return 1;
}
