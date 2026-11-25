typedef int s32;
typedef float f32;

#define PI 0x1.921fb4p+1f
#define PI_2 0x1.921fb4p+0f

struct Joint {
    char pad00[0x20];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual f32 length();
};

/* joints are laid out 0x50 apart in the skeleton */
struct JointSlot {
    Joint j;
    char pad[0x50 - sizeof(Joint)];
};

struct Body {
    char pad000[0x250];
    JointSlot spine[3]; /* 0x250 */
};

struct Params {
    char pad000[0x268];
    f32 lean;           /* 0x268 */
};

struct Angle {
    f32 a;
    Angle() {}
    Angle(f32 v) : a(v) {}
    Angle(const Angle &o) : a(o.a) {}
    f32 value() const { return a; }
};

extern "C" {
f32 func_0059D2A0(f32 x);           /* arc cosine (libm) */
f32 func_0057D1F0(f32 a) throw();   /* tangent of the math library; a C library function cannot throw */
Angle func_004233C0(f32 a, f32 b, f32 c); /* angle of a triangle from its three sides */
}

static inline Joint *spine(Body *b, int i) { return &b->spine[i].j; }
static inline f32 minf(const f32 &a, const f32 &b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 sqrtf_(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline f32 absf(f32 x) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

/* Lean angle of the spine so that its three segments (a, b, c) span `len`.
   The cosine of the bend solves A*x^2 + B*x + C = 0 with A = 4ac, B = b*t, t = -2(a + c) and
   C = a^2 + b^2 + c^2 - len^2 - 2ac; the root inside [-1, 1] is taken (the smaller one when both
   are) and the stored lean is corrected by the triangle that root gives.

   `v` is one scratch variable used for four values in turn (the constant term, the chosen cosine,
   the deviation from a right angle, the correction). That is how the original was written: the
   compiler keeps a variable set in several blocks in one register, and both the register of the
   later values and the allocation of the temporaries of the quadratic follow from it. `t` is
   reused the same way for the half segment further down. */
extern "C" f32 func_00417110(Params *p, Body *body, f32 len) {
    f32 lean = p->lean;
    f32 a = spine(body, 0)->length();
    f32 b = spine(body, 1)->length();
    f32 c = spine(body, 2)->length();
    f32 r[2];
    f32 t = (a + c) * -2.0f;
    f32 v = a * a + b * b + c * c - len * len - 2.0f * a * c;
    f32 d = sqrtf_(b * b * t * t - a * 16.0f * c * v);
    f32 inv = 1.0f / (a * 8.0f * c);
    r[0] = (-b * t - d) * inv;
    r[1] = (-b * t + d) * inv;

    if (-1.0f <= r[0] && r[0] <= 1.0f && (r[1] < -1.0f || 1.0f < r[1])) {
        v = r[0];
    } else if (-1.0f <= r[1] && r[1] <= 1.0f && (r[0] < -1.0f || 1.0f < r[0])) {
        v = r[1];
    } else if (-1.0f <= r[0] && r[0] <= 1.0f && -1.0f <= r[1] && r[1] <= 1.0f) {
        v = minf(r[0], r[1]);
    } else {
        return lean;
    }
    v = absf(PI_2 - func_0059D2A0(v));
    if (PI_2 < v) {
        t = 0.5f;
        t = b * t;
        t = t / func_0057D1F0(PI - v);
        v = func_004233C0(c + t, len, a + t).value();
        if (0.0f < v) lean -= v;
    }
    return lean;
}
