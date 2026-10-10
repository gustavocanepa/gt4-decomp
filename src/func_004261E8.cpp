typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec4 {
    union {
        u128 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec4() {}
    float &operator[](int i) { return (&f.x)[i]; }
    Vec4(const Vec4 &o) { q = o.q; }
    void sub2(const Vec4 &o)
    {
        (*this)[0] -= o.f.x;
        (*this)[1] -= o.f.y;
    }
};

struct Circle {
    Vec4 pos;
    float radius;
};

static inline float sqrtf_(float x)
{
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static inline Vec4 sub2d(Vec4 a, const Vec4 &b)
{
    a.sub2(b);
    return a;
}

static inline float length2d(Vec4 v)
{
    return sqrtf_(v.f.x * v.f.x + v.f.y * v.f.y);
}

extern "C" float func_004261E8(Circle *c, Vec4 *p)
{
    return length2d(sub2d(*p, c->pos)) - c->radius;
}
