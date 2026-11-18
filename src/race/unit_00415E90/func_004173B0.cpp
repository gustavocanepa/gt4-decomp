/* compiler: ee-gcc2.96-no-strict-aliasing */
/* func_004173B0 (inferred): places the driver's hands on the steering wheel for one frame and
 * fills the grip frame `g` for the arm IK (func_0041C3F8, see func_00416FD8). Builds the four
 * pairs of hand solvers (easy, fixed, free, single-handed) and picks a pair from the mode; the
 * single-handed pose interpolates three keyframes by p->phase (0..3). Runs each hand's solver
 * through its vtable, applies forced results, then computes the shoulder point from the spine
 * length, lean (sincos) and steering angle, adjusts the shoulder angles from how far each hand
 * target is (four clamped linear maps), sets the hand twist from the elbow triangle angles
 * (func_004233C0) and finally transforms everything into world space by the wheel frame.
 * Several shapes are load-bearing for the match (knowledge/attempts.jsonl): Angle with a copy
 * constructor (BLKmode temporaries), the unit's Vec operator[] / += forms, the arm reference,
 * the early `active` read, and the statement orders of the keyframe and shoulder blocks. */
typedef int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

#define PI 0x1.921fb4p+1f
#define PI_2 0x1.921fb4p+0f
#define PI_4 0x1.921fb4p-1f
#define PI_10 0x1.41b2f4p-2f

struct Vec {
    union { u128 q; struct { f32 x, y, z, w; }; };
    Vec() {}
    Vec(f32 a, f32 b, f32 c) { x = a; y = b; z = c; }
    Vec(const Vec &v) { q = v.q; }
    Vec &operator=(const Vec &v) { q = v.q; return *this; }
    Vec &operator+=(const Vec &v) { x = (*this)[0] + v[0]; y = (*this)[1] + v[1]; z = (*this)[2] + v[2]; return *this; }
    Vec &operator-=(const Vec &v) { x = (*this)[0] - v[0]; y = (*this)[1] - v[1]; z = (*this)[2] - v[2]; return *this; }
    Vec &operator*=(f32 s) { x *= s; y *= s; z *= s; return *this; }
    f32 &operator[](int n) { return *(f32 *)((char *)this + n * 4); }
    const f32 &operator[](int n) const { return *(const f32 *)((const char *)this + n * 4); }
    f32 lengthSq() const { return x * x + y * y + z * z; }
} __attribute__((aligned(16)));
static inline Vec operator+(const Vec &a, const Vec &b) { Vec r(a); r += b; return r; }
static inline Vec operator-(const Vec &a, const Vec &b) { Vec r(a); r -= b; return r; }
static inline Vec operator*(const Vec &a, f32 s) { Vec r(a); r *= s; return r; }

struct Quat {
    union { u128 q; struct { f32 x, y, z, w; }; };
    Quat() {}
    Quat(const Quat &v) { q = v.q; }
    Quat &operator=(const Quat &v) { q = v.q; return *this; }
} __attribute__((aligned(16)));

struct Mat3 { u128 r[3]; };
struct Xform { Vec pos; Mat3 m; };

struct Joint {
    Vec pos;            /* 0x00 */
    Quat rot;           /* 0x10 */
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

/* the driver's skeleton; the root joint is the body itself */
struct Body : Joint {
    char pad30[0x250 - sizeof(Joint)];
    JointSlot spine[3]; /* 0x250 */
    char pad340[0x360 - 0x340];
    JointSlot upperL;   /* 0x360 */
    JointSlot upperR;   /* 0x3B0 */
    JointSlot foreL;    /* 0x400 */
    JointSlot foreR;    /* 0x450 */
    char pad4A0[0x590 - 0x4A0];
    JointSlot handL;    /* 0x590 */
    JointSlot handR;    /* 0x5E0 */
};

/* the steering wheel frame */
struct Wheel {
    Vec pos;            /* 0x00 */
    Quat rot;           /* 0x10 */
    Vec gripL;          /* 0x20 */
    Vec gripR;          /* 0x30 */
    Vec center;         /* 0x40 */
    Vec top;            /* 0x50 */
    char pad60[0x120 - 0x60];
    s32 hand;           /* 0x120 */
    char pad124[0x12C - 0x124];
    s32 fixed;          /* 0x12C */
};

struct Grip {
    Quat wheel;         /* 0x00 */
    Vec posL;           /* 0x10 */
    Vec gripL;          /* 0x20 */
    Vec gripR;          /* 0x30 */
    Vec shoulder;       /* 0x40 */
    Vec targetL;        /* 0x50 */
    Vec targetR;        /* 0x60 */
    Vec dirL;           /* 0x70 */
    Vec dirR;           /* 0x80 */
    Vec handDirL;       /* 0x90 */
    Vec handDirR;       /* 0xA0 */
    Vec up;             /* 0xB0 */
};

struct Pair { f32 l, r; };

struct Params {
    char pad00[0x18];
    f32 wristL;         /* 0x18 */
    f32 wristR;         /* 0x1C */
    f32 leanL;          /* 0x20 */
    f32 leanR;          /* 0x24 */
    f32 twistL;         /* 0x28 */
    f32 twistR;         /* 0x2C */
    char pad30[0x40 - 0x30];
    f32 shoulderL;      /* 0x40 */
    f32 shoulderR;      /* 0x44 */
    f32 pitchL;         /* 0x48 */
    f32 pitchR;         /* 0x4C */
    char pad50[0x5C - 0x50];
    f32 steer;          /* 0x5C */
    char pad60[0xA8 - 0x60];
    s32 autoShoulder;   /* 0xA8 */
    s32 handMode;       /* 0xAC */
    s32 fixedL;         /* 0xB0 */
    s32 fixedR;         /* 0xB4 */
    char padB8[0xBC - 0xB8];
    s32 active;         /* 0xBC */
    s32 useGrips;       /* 0xC0 */
    char padC4[0x200 - 0xC4];
    s32 rawSteer;       /* 0x200 */
    char pad204[0x220 - 0x204];
    Pair in0;           /* 0x220 */
    Pair in1;           /* 0x228 */
    Pair in2;           /* 0x230 */
    Pair holdA;         /* 0x238 */
    Pair holdB;         /* 0x240 */
    Pair base;          /* 0x248 */
    Pair key[3];        /* 0x250 */
    f32 lean;           /* 0x268 */
    char pad26C[0x280 - 0x26C];
    Vec gripOfsL;       /* 0x280 */
    Vec gripOfsR;       /* 0x290 */
    Pair shoulderBase;  /* 0x2A0 */
    Pair pitchBase;     /* 0x2A8 */
    Vec armOfs;         /* 0x2B0 */
    Vec shOfs;          /* 0x2C0 */
    f32 reach;          /* 0x2D0 */
    s32 freeHands;      /* 0x2D4 */
    s32 fixedLean;      /* 0x2D8 */
    s32 forceL;         /* 0x2DC */
    s32 forceR;         /* 0x2E0 */
    s32 holdMode;       /* 0x2E4 */
    char pad2E8[0x2F0 - 0x2E8];
    Vec keyPos[3];      /* 0x2F0 */
    Pair keyHold[3];    /* 0x320 */
    char pad338[0x340 - 0x338];
    Vec posOfs;         /* 0x340 */
    f32 phase;          /* 0x350 */
};

struct Angle {
    f32 a;
    Angle() {}
    Angle(f32 v) : a(v) {}
    Angle(const Angle &o) : a(o.a) {}
    f32 value() const { return a; }
};

struct HandleSolverBase {
    s32 side;           /* 0x00 */
    char pad04[0x10 - 0x04];
    Vec pos;            /* 0x10 */
    Vec dir;            /* 0x20 */
    Vec axis;           /* 0x30 */
    f32 m40, m44, m48;  /* 0x40 */
    virtual void v1();
    virtual s32 solve(Angle *a, Angle *b, Wheel *w, f32 c, f32 d);
};

struct EasyHandleSolver : HandleSolverBase {
    EasyHandleSolver(s32 side) __asm__("func_00415470");
};
struct FixedHandleSolver : HandleSolverBase {
    FixedHandleSolver(s32 side) __asm__("func_004154E0");
};
struct FreeHandleSolver : HandleSolverBase {
    const Vec *source;
    FreeHandleSolver(s32 side, const Vec *source) __asm__("func_00415608");
};
struct SingleHandedHandleSolver : HandleSolverBase {
    Vec target;         /* 0x50 */
    f32 m60, m64, m68, m6C, m70;
    s32 m74;
    SingleHandedHandleSolver(s32 side) __asm__("func_00415CD8");
};

extern "C" {
void func_00421C58(Mat3 *out, const Quat *q);
f32 func_0041B9D8(Joint *j);
Joint *func_0041A988(Body *b, s32 i);
f32 func_00416EB0(Params *p);
f32 func_00417110(Params *p, Body *b, f32 len);
void func_0057D8A0(f32 a, f32 *s, f32 *c);
f32 func_0057D1F0(f32 a);
void func_00487830(Quat *out, const Vec *axis, f32 angle);
void func_00487950(Quat *q, f32 angle);
Vec Numerical_Math__Quaternion__rotate(const Quat *q, const Vec *v);
Angle func_004233C0(f32 a, f32 b, f32 c);
void func_00418818(Xform *xf, Vec *out, const Vec *in);
}

static inline f32 maxf(const f32 &a, const f32 &b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(const f32 &a, const f32 &b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 clampf(const f32 &v, const f32 &lo, const f32 &hi) { return minf(maxf(v, lo), hi); }
static inline f32 sqrtf_(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline Vec rotate(const Quat &q, const Vec &v) { return Numerical_Math__Quaternion__rotate(&q, &v); }
static inline void toWorld(Xform *xf, Vec *out, const Vec &in) { func_00418818(xf, out, &in); }

/* maps [in0, in1] linearly onto [out0, out1] */
struct LinearMap {
    f32 scale, offset;
    LinearMap(f32 in0, f32 in1, f32 out0, f32 out1) {
        f32 inv = 1.0f / (in1 - in0);
        scale = (out1 - out0) * inv;
        offset = inv * (in1 * out0 - in0 * out1);
    }
    f32 operator()(f32 v) const { return scale * v + offset; }
};
static inline f32 clamp01(f32 v) { return clampf(v, 0.0f, 1.0f); }
static inline f32 clampMap(const LinearMap &m, f32 v, f32 lo, f32 hi) { return clampf(m(v), lo, hi); }

static inline void setRot(Quat *q, const Vec &axis, const Angle &a) { func_00487830(q, &axis, a.a); }
static inline void rotX(Quat *q, const Angle &a) { func_00487950(q, a.a); }
static inline int pick(Wheel *w, HandleSolverBase *s) {
    int m = w->hand;
    if ((m == 1 && !s->side) || (m == 2 && s->side)) return 1;
    return 0;
}
static inline f32 maxOf(const f32 &a, const f32 &b) { return a < b ? b : a; }
static inline f32 normSteer(const Angle &a) {
    f32 v = a.a;
    f32 lim = maxOf(PI_4, 0.0f);
    f32 lo = -lim;
    return ((v - lo) / (lim - lo) - 0.5f) * 0x1.333332p-3f * PI;
}

extern "C" s32 func_004173B0(Params *p, Body *b, Wheel *w, Grip *g) {
    g->wheel = w->rot;
    SingleHandedHandleSolver single0(0), single1(1);
    FixedHandleSolver fixed0(0), fixed1(1);
    EasyHandleSolver easy0(0), easy1(1);
    FreeHandleSolver free0(0, &w->center), free1(1, &w->center);
    HandleSolverBase *sL, *sR;
    if (p->active == 0) {
        sL = &easy0;
        sR = &easy1;
        p->handMode = 0;
    } else if (w->fixed == 1) {
        p->handMode = w->fixed;
        sL = &fixed0;
        sR = &fixed1;
    } else if (p->freeHands) {
        sL = &free0;
        sR = &free1;
    } else {
        Vec pos(0.0f, 0.0f, 0.0f);
        f32 holdX = 0.0f, holdY = 0.0f, offL = 0.0f, offR = 0.0f;
        f32 t = p->phase;
        if (0.0f <= t && t <= 1.0f) {
            f32 u = 1.0f - t;
            pos = p->keyPos[0] * u + p->keyPos[1] * t;
            holdX = p->keyHold[0].l * u + p->keyHold[1].l * t;
            holdY = p->keyHold[0].r * u + p->keyHold[1].r * t;
            offL = p->key[0].l * u + p->key[1].l * t - p->base.l;
            offR = p->key[0].r * u + p->key[1].r * t - p->base.r;
        } else if (t <= 2.0f) {
            f32 s = t - 1.0f;
            f32 u = 1.0f - s;
            pos = p->keyPos[1] * u + p->keyPos[2] * s;
            holdX = p->keyHold[1].l * u + p->keyHold[2].l * s;
            holdY = p->keyHold[1].r * u + p->keyHold[2].r * s;
            offL = p->key[1].l * u + p->key[2].l * s - p->base.l;
            offR = p->key[1].r * u + p->key[2].r * s - p->base.r;
        } else if (t <= 3.0f) {
            f32 s = t - 2.0f;
            f32 u = 1.0f - s;
            pos = p->keyPos[2] * u + p->keyPos[0] * s;
            holdX = p->keyHold[2].l * u + p->keyHold[0].l * s;
            holdY = p->keyHold[2].r * u + p->keyHold[0].r * s;
            offL = p->key[2].l * u + p->key[0].l * s - p->base.l;
            offR = p->key[2].r * u + p->key[0].r * s - p->base.r;
        }
        if (pick(w, &single0)) {
            single0.target = pos;
            single0.m68 = p->holdA.l;
            single0.m6C = p->holdB.l;
            single0.m60 = holdX;
            single0.m64 = holdY;
        }
        if (pick(w, &single1)) {
            single1.target = pos;
            single1.m60 = holdX;
            single1.m64 = holdY;
            single1.m68 = p->holdA.r;
            single1.m6C = p->holdB.r;
        }
        single0.m70 = offL;
        single0.m74 = p->holdMode;
        single1.m70 = offR;
        single1.m74 = p->holdMode;
        p->handMode = 0;
        sL = &single0;
        sR = &single1;
    }
    s32 ok[2] = { 1, 1 };
    {
        Angle a(p->in0.l), c(p->in1.l);
        ok[0] = sL->solve(&a, &c, w, p->in2.l, func_00416EB0(p));
    }
    {
        Angle a(p->in0.r), c(p->in1.r);
        ok[1] = sR->solve(&a, &c, w, p->in2.r, func_00416EB0(p));
    }
    if (p->forceL == 1) ok[0] = 1;
    else if (p->forceL == 2) ok[0] = 0;
    if (p->forceR == 1) ok[1] = 1;
    else if (p->forceR == 2) ok[1] = 0;
    p->fixedL = ok[0];
    p->fixedR = ok[1];
    f32 steer;
    if (p->rawSteer) steer = Angle(p->steer).value();
    else steer = normSteer(Angle(p->steer));
    f32 len = func_0041B9D8(b) + func_0041B9D8(&b->spine[0].j) + func_0041B9D8(&b->spine[1].j) +
              func_0041B9D8(&b->spine[2].j) + p->reach;
    Vec center = w->center;
    Vec gripL = w->gripL + p->gripOfsL;
    Vec gripR = w->gripR + p->gripOfsR;
    Vec axisL = sL->axis;
    Vec axisR = sR->axis;
    Vec posL = sL->pos;
    Vec posR = sR->pos;
    len *= 1.0f - func_0057D1F0(p->lean) * 0x1.999998p-5f;
    f32 lean;
    if (p->fixedLean == 0) lean = func_00417110(p, b, len - b->length());
    else lean = p->lean;
    f32 s, c;
    func_0057D8A0(lean, &s, &c);
    Vec shoulderPos(0.0f, len * c, len * s);
    Vec &arm = shoulderPos;
    Vec up(0.0f, s, -c);
    Quat q;
    setRot(&q, Vec(0.0f, -s, c), steer);
    arm = rotate(q, arm);
    s32 active = p->active;
    arm = arm + center + p->armOfs;
    if (active) {
        f32 shL = PI_10, roll = 0.0f, shR = PI_10;
        f32 dx = posL[0] - arm[0];
        {
            LinearMap m(func_0041A988(b, 15)->length(), 0.0f, 0.0f, 1.0f);
            dx = clampMap(m, dx, 0.0f, 1.0f) * 0x1.e28c6ep-3f;
            shL += dx;
            shR -= dx * 0.25f;
            roll += dx * 0x1.999998p-5f;
        }
        f32 dz = posL[2] - arm[2];
        {
            LinearMap m(func_0041B9D8(&b->upperL.j) + func_0041B9D8(&b->foreL.j) + func_0041B9D8(&b->handL.j), 0.0f, 0.0f, 1.0f);
            dz = clampMap(m, dz, 0.0f, 1.0f) * -0x1.e28c6ep-2f;
            shL += dz;
            shR -= dz * 0.25f;
        }
        dx = arm[0] - posR[0];
        {
            LinearMap m(func_0041A988(b, 16)->length(), 0.0f, 0.0f, 1.0f);
            dx = clampMap(m, dx, 0.0f, 1.0f) * 0x1.e28c6ep-3f;
            shR += dx;
            shL -= dx * 0.25f;
            roll += dx * 0x1.999998p-5f;
        }
        dz = posR[2] - arm[2];
        {
            LinearMap m(func_0041B9D8(&b->upperR.j) + func_0041B9D8(&b->foreR.j) + func_0041B9D8(&b->handR.j), 0.0f, 0.0f, 1.0f);
            dz = clampMap(m, dz, 0.0f, 1.0f) * -0x1.e28c6ep-2f;
            shR += dz;
            shL -= dz * 0.25f;
        }
        p->shoulderL = shL * 0.75f + p->shoulderBase.l;
        p->shoulderR = shR * 0.75f + p->shoulderBase.r;
        rotX(&q, roll);
        arm -= center;
        arm = rotate(q, arm);
        arm += center;
    }
    f32 pitch = 0.0f;
    if (p->fixedLean) pitch = PI_10;
    p->pitchL = p->pitchBase.l + pitch;
    p->autoShoulder = 0;
    p->pitchR = p->pitchBase.r + pitch;
    if (p->active) {
        Quat qL, qR;
        Vec top = w->top;
        f32 a, a2;
        f32 da = sqrtf_((posL - arm).lengthSq());
        f32 db = sqrtf_((top - posL).lengthSq());
        f32 dc = sqrtf_((arm - top).lengthSq());
        a = func_004233C0(da, db, dc).value();
        da = sqrtf_((posR - arm).lengthSq());
        db = sqrtf_((top - posR).lengthSq());
        a2 = func_004233C0(da, db, dc).value();
        a = PI_2 - a;
        a2 = PI_2 - a2;
        a = clampf(a, -0x1.41b2f4p+0f, 0x1.41b2f4p+0f);
        a2 = clampf(a2, -0x1.41b2f4p+0f, 0x1.41b2f4p+0f);
        setRot(&qL, sL->dir, -a);
        setRot(&qR, sR->dir, a2);
        axisL = rotate(qL, axisL);
        axisR = rotate(qR, axisR);
        g->dirL = sL->dir;
        g->dirR = sR->dir;
        g->handDirL = axisL;
        g->handDirR = axisR;
        p->leanL = clamp01(sL->m40);
        p->leanR = clamp01(sR->m40);
        p->wristL = clamp01(sL->m44);
        p->wristR = clamp01(sR->m44);
        p->twistL = sL->m48 + p->base.l;
        p->twistR = sR->m48 + p->base.r;
    }
    {
        Xform xf;
        xf.pos = w->pos;
        func_00421C58(&xf.m, &w->rot);
        toWorld(&xf, &g->posL, center + p->posOfs);
        toWorld(&xf, &g->targetL, posL);
        toWorld(&xf, &g->targetR, posR);
        toWorld(&xf, &g->shoulder, arm);
        g->shoulder += p->shOfs;
        if (p->useGrips) {
            toWorld(&xf, &g->gripL, gripL);
            toWorld(&xf, &g->gripR, gripR);
        }
        Vec u = rotate(Quat(g->wheel), up);
        g->up = u;
    }
    return 1;
}
