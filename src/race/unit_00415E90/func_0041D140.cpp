/* compiler: ee-gcc2.96-no-strict-aliasing */
/* func_0041D140 (inferred): poses the driver's arms on the steering wheel. Places the shoulder
 * joints from the body transform, optionally derives the shoulder angles from how far each
 * target is (reach/lean), rotates the shoulders, builds wheel-relative pole vectors, solves the
 * two-bone IK of each arm (func_00420510) and then refines the wrists, hand orientation and
 * forearm/upper-arm twist. Writes the IK reached flags to `res` and the poles to `dbg` if given.
 * Several shapes are load-bearing for the match (see knowledge/attempts.jsonl): the const-ref
 * min/max helpers, the two-armed reach ternaries, maxOf(range), the func_00420510 prototype
 * order and the Vec* / Quat* returns of func_0041C6F8 / func_004225E0. */
typedef int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec {
    union { u128 q; struct { f32 x, y, z, w; }; };
    Vec() {}
    Vec(const f32 &a, const f32 &b, const f32 &c) { x = a; y = b; z = c; }
    Vec(const Vec &v) { q = v.q; }
    Vec &operator=(const Vec &v) { q = v.q; return *this; }
    Vec &operator+=(const Vec &v) { f32 &tx = x, &ty = y, &tz = z; const f32 &vx = v.x, &vy = v.y, &vz = v.z; tx += vx; ty += vy; tz += vz; return *this; }
    Vec &operator-=(const Vec &v) { f32 &tx = x, &ty = y, &tz = z; const f32 &vx = v.x, &vy = v.y, &vz = v.z; tx -= vx; ty -= vy; tz -= vz; return *this; }
    void setNeg(const Vec &v) { x = -v.x; y = -v.y; z = -v.z; }
    Vec operator-() const { Vec r; r.setNeg(*this); return r; }
    f32 lengthSq() const { return x * x + y * y + z * z; }
} __attribute__((aligned(16)));
static inline Vec operator+(const Vec &a, const Vec &b) { Vec r(a); r += b; return r; }
static inline Vec operator-(const Vec &a, const Vec &b) { Vec r(a); r -= b; return r; }

struct Quat {
    union { u128 q; struct { f32 x, y, z, w; }; };
    Quat() {}
    Quat(const Quat &v) { q = v.q; }
    Quat &operator=(const Quat &v) { q = v.q; return *this; }
    Quat conj() const { Quat r; r.x = -x; r.y = -y; r.z = -z; r.w = w; return r; }
} __attribute__((aligned(16)));

struct Degree {
    f32 d;
    Degree(f32 v) : d(v) {}
    Degree(const Degree &o) : d(o.d) {}
};

struct Angle {
    f32 a;
    Angle() {}
    Angle(f32 v) : a(v) {}
    Angle(const Angle &o) : a(o.a) {}
    Angle(Degree d) __asm__("func_00420FC8");
    f32 value() const { return a; }
    Angle operator-() const { return Angle(-a); }
    Angle operator+() const { return *this; }
    Angle operator*(f32 s) const { return Angle(a * s); }
    Angle &operator-=(const Angle &o) { a -= o.a; return *this; }
    Angle &operator+=(const Angle &o) { a += o.a; return *this; }
};

struct Mat3 { u128 r[3]; };
struct Xform { Vec pos; Mat3 m; };

struct Joint {
    Vec pos;
    Quat rot;
    void *vt;
    char pad24[0x40 - 0x24];
    const Quat &rotation() const { return rot; }
    f32 length;
    char pad44[0x50 - 0x44];
};

struct Body {
    char pad0[0x2F0];
    Vec pos;            /* 0x2F0 */
    Quat rot;           /* 0x300 */
    char pad310[0x340 - 0x310];
    Vec shoulderOfsL;   /* 0x340 */
    Vec shoulderOfsR;   /* 0x350 */
    Joint upperL;       /* 0x360 */
    Joint upperR;       /* 0x3B0 */
    Joint foreL;        /* 0x400 */
    Joint foreR;        /* 0x450 */
    char pad4A0[0x4F0 - 0x4A0];
    Joint shoulderL;    /* 0x4F0 */
    Joint shoulderR;    /* 0x540 */
    Joint handL;        /* 0x590 */
    Joint handR;        /* 0x5E0 */
};

struct Grip {
    Quat wheel;         /* 0x00 */
    char pad10[0x50 - 0x10];
    Vec targetL;        /* 0x50 */
    Vec targetR;        /* 0x60 */
    Vec dirL;           /* 0x70 */
    Vec dirR;           /* 0x80 */
    Vec handDirL;       /* 0x90 */
    Vec handDirR;       /* 0xA0 */
};

struct Params {
    f32 reachL;         /* 0x00 */
    f32 reachR;         /* 0x04 */
    char pad08[0x18 - 0x08];
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
    char pad50[0xA8 - 0x50];
    s32 autoShoulder;   /* 0xA8 */
    s32 handMode;       /* 0xAC */
    s32 fixedL;         /* 0xB0 */
    s32 fixedR;         /* 0xB4 */
    char padB8[0xCC - 0xB8];
    s32 simple;         /* 0xCC */
};

struct Result { char pad[0xC]; s32 reachedL; s32 reachedR; char pad14[0x20 - 0x14]; };
struct Debug { char pad[0x100]; Vec poleL; Vec poleR; };

extern "C" {
void func_00421C58(Mat3 *out, const Quat *q);
Vec func_004187A0(Xform *xf, const Vec *v);
f32 func_0041B9D8(Joint *j);
Vec func_0041B898(Joint *j);
Vec func_0041B9E0(Joint *j);
void func_0041BAC0(Joint *j, const Angle *angle);
void func_00487EA8(Quat *q, f32 x, f32 y);
Quat func_0048D530(const Quat *a, const Quat *b);
}
static inline Quat operator*(const Quat &a, const Quat &b) { Quat r = func_0048D530(&a, &b); return r; }
extern "C" {
Vec Numerical_Math__Quaternion__rotate(const Quat *q, const Vec *v);
Quat *func_004225E0(Quat *q, const Angle *angle);
Angle func_00423450(const Vec *a, const Vec *b);
Vec *func_0041C6F8(Vec *out, Joint *j, const Vec *axis, const Vec *base, const Vec *target, f32 reach, f32 angle);
s32 func_00420510(s32 *flag, Joint *upper, Joint *lower, f32 l1, f32 l2, const Vec *pole, const Vec *base, const Vec *target, const Vec *axis, const Vec *up, f32 tol,
                  const Angle &minAngle, s32 mode);
s32 func_0041C458(Params *p, Joint *hand, Joint *fore, Vec *dir, Vec *handDir, const Angle &factor, f32 t);
Vec func_00421DC0(const Quat *q);
Vec func_00421D88(const Quat *q);
Angle func_00423AA0(const Vec *a, const Vec *b, const Vec *axis);
void func_004887D8(Quat *out, const Vec *a, const Vec *b);
void func_00487830(Quat *out, const Vec *axis, f32 angle);
void func_004878C0(Quat *q, const Vec *axis, f32 angle);
}

extern Vec D_00622B00;
extern Vec D_00622B10;
extern Vec D_00622B30;
extern Vec D_00622B40;

static inline void setQ(Quat &r, f32 x, f32 y, f32 z, f32 w) { r.x = x; r.y = y; r.z = z; r.w = w; }
static inline Quat makeQuat(f32 x, f32 y, f32 z, f32 w) { Quat r; setQ(r, x, y, z, w); return r; }
static inline f32 maxf(const f32 &a, const f32 &b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(const f32 &a, const f32 &b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 clampf(const f32 &v, const f32 &lo, const f32 &hi) { return minf(maxf(v, lo), hi); }
static inline f32 maxOf(const f32 &a, const f32 &b) { return a < b ? b : a; }
static inline f32 clamp3(const f32 &lo, const f32 &hi, const f32 &v) { return minf(maxf(v, lo), hi); }
static inline f32 remap(const f32 &t, f32 lo, f32 hi) { f32 v = t * (hi - lo); return clamp3(lo, hi, v); }
static inline void euler(Quat *q, const Angle &x, const Angle &y) { func_00487EA8(q, x.a, y.a); }
static inline void setRot(Quat *q, const Vec &axis, const Angle &a) { func_00487830(q, &axis, a.a); }
static inline void turn(Quat *q, const Vec &axis, const Angle &a) { func_004878C0(q, &axis, a.a); }

#define PI_2 0x1.921fb4p+0f
#define PI_10 0x1.41b2f4p-2f

extern "C" s32 func_0041D140(Params *p, Body *b, Grip *g, s32 unused, Result *res, Debug *dbg) {
    Vec endL, endR;
    Quat qL, qR;
    Result local;
    s32 flag;
    if (res == 0) res = &local;
    {
        Xform xf;
        xf.pos = b->pos;
        func_00421C58(&xf.m, &b->rot);
        b->shoulderL.pos = func_004187A0(&xf, &b->shoulderOfsL);
        b->shoulderR.pos = func_004187A0(&xf, &b->shoulderOfsR);
        if (p->autoShoulder) {
            Vec a = b->shoulderOfsL + Vec(func_0041B9D8(&b->shoulderL), 0.0f, 0.0f);
            Vec c = b->shoulderOfsR + Vec(-func_0041B9D8(&b->shoulderR), 0.0f, 0.0f);
            a = func_004187A0(&xf, &a);
            c = func_004187A0(&xf, &c);
            a = g->targetL - a;
            c = g->targetR - c;
            f32 lenL = func_0041B9D8(&b->upperL) + func_0041B9D8(&b->foreL) + func_0041B9D8(&b->handL);
            f32 lenR = func_0041B9D8(&b->upperR) + func_0041B9D8(&b->foreR) + func_0041B9D8(&b->handR);
            f32 rL = clampf(a.lengthSq() / (lenL * lenL), 0.0f, 1.0f);
            f32 rR = clampf(c.lengthSq() / (lenR * lenR), 0.0f, 1.0f);
            if (rL < 0.5f) rL = 0.0f;
            else rL = (rL - 0.5f) * 2.0f;
            f32 fR = rR < 0.5f ? 0.0f : (rR - 0.5f) * 2.0f;
            f32 range = maxOf(PI_10, 0.0f);
            f32 lo = 0.0f;
            p->shoulderL = remap(rL + (p->reachL - 0.5f) * 0x1.333332p-2f + (p->leanL - 0.5f) * 0x1.999998p-5f, lo, range);
            p->shoulderR = remap(fR + (p->reachR - 0.5f) * 0x1.333332p-2f + (p->leanR - 0.5f) * 0x1.999998p-5f, lo, range);
        }
        euler(&qL, -Angle(p->shoulderL), +Angle(p->pitchL));
        euler(&qR, +Angle(p->shoulderR), -Angle(p->pitchR));
        b->shoulderL.rot = b->rot * qL;
        b->shoulderR.rot = b->rot * qR;
    }
    endL = func_0041B898(&b->shoulderL);
    endR = func_0041B898(&b->shoulderR);
    Vec poleL, poleR;
    if (!p->fixedL) {
        Quat inv = makeQuat(-b->rot.x, -b->rot.y, -b->rot.z, b->rot.w);
        Vec d = Numerical_Math__Quaternion__rotate(&inv, &g->dirL);
        f32 t = clampf(d.y, 0.0f, 1.0f) * PI_10;
        Quat q = b->shoulderL.rot;
        func_004225E0(&q, &Angle(t));
        b->shoulderL.rot = q;
    }
    if (!p->fixedR) {
        Quat inv = makeQuat(-b->rot.x, -b->rot.y, -b->rot.z, b->rot.w);
        Vec d = Numerical_Math__Quaternion__rotate(&inv, &g->dirR);
        f32 t = clampf(d.y, 0.0f, 1.0f) * -PI_10;
        Quat q = b->shoulderR.rot;
        func_004225E0(&q, &Angle(t));
        b->shoulderR.rot = q;
    }
    endL = func_0041B898(&b->shoulderL);
    endR = func_0041B898(&b->shoulderR);

    {
        Vec up = Numerical_Math__Quaternion__rotate(&Quat(g->wheel), &D_00622B10);
        f32 angL = PI_2 - func_00423450(&up, &g->dirL).value();
        f32 angR = PI_2 - func_00423450(&up, &g->dirR).value();
        func_0041C6F8(&poleL, &b->shoulderL, &D_00622B00, &endL, &g->targetL, p->reachL, angL);
        func_0041C6F8(&poleR, &b->shoulderR, &D_00622B30, &endR, &g->targetR, p->reachR, angR);
    }
    if (dbg) {
        dbg->poleL = poleL;
        dbg->poleR = poleR;
    }

    {
        Angle minAngle(Degree(5.0f));
        func_00420510(&flag, &b->upperL, &b->foreL, func_0041B9D8(&b->upperL), func_0041B9D8(&b->foreL) + func_0041B9D8(&b->handL), &poleL,
                      &endL, &g->targetL, &D_00622B00, &D_00622B40, 0.0f,
                      minAngle, 0);
    }
    {
        Angle minAngle(Degree(5.0f));
        func_00420510(&flag, &b->upperR, &b->foreR, func_0041B9D8(&b->upperR), func_0041B9D8(&b->foreR) + func_0041B9D8(&b->handR), &poleR,
                      &endR, &g->targetR, &D_00622B30, &D_00622B40, 0.0f,
                      minAngle, 0);
    }
    b->handL.pos = func_0041B898(&b->foreL);
    b->handR.pos = func_0041B898(&b->foreR);
    {
        const Quat &fl = b->foreL.rotation(), &fr = b->foreR.rotation();
        b->handL.rot = fl;
        b->handR.rot = fr;
    }

    if (p->simple) {
        Quat rotL = b->handL.rot;
        Quat rotR = b->handR.rot;
        Vec axisL, axisR;
        axisL = func_0041B9E0(&b->handL);
        axisR = func_0041B9E0(&b->handR);
        f32 twL = func_00423AA0(&-func_00421DC0(&rotL), &g->dirL, &axisL).value();
        f32 twR = func_00423AA0(&-func_00421DC0(&rotR), &g->dirR, &axisR).value();
        func_0041BAC0(&b->handL, &Angle(twL * 0x1.999998p-1f));
        func_0041BAC0(&b->handR, &Angle(twR * 0x1.999998p-1f));
        func_0041BAC0(&b->foreL, &Angle(twL * 0x1.999998p-3f));
        func_0041BAC0(&b->foreR, &Angle(twR * 0x1.999998p-3f));
        return 1;
    }

    f32 bendL = (p->leanL - 0.5f) * PI_2;
    f32 bendR = (0.5f - p->leanR) * PI_2;
    if (p->wristL > 0.0f) {
        func_0041C458(p, &b->handL, &b->foreL, &g->dirL, &g->handDirL, +Angle(-bendL), p->wristL);
        {
            Angle minAngle(Degree(5.0f));
            func_00420510(&flag, &b->upperL, &b->foreL, func_0041B9D8(&b->upperL), func_0041B9D8(&b->foreL), &poleL,
                          &endL, &b->handL.pos, &D_00622B00, &D_00622B40, 0x1.47ae14p-6f,
                          minAngle, 0);
        }
        b->handL.pos = func_0041B898(&b->foreL);
    }
    if (p->wristR > 0.0f) {
        func_0041C458(p, &b->handR, &b->foreR, &g->dirR, &g->handDirR, +Angle(-bendR), p->wristR);
        {
            Angle minAngle(Degree(5.0f));
            func_00420510(&flag, &b->upperR, &b->foreR, func_0041B9D8(&b->upperR), func_0041B9D8(&b->foreR), &poleR,
                          &endR, &b->handR.pos, &D_00622B30, &D_00622B40, 0x1.47ae14p-6f,
                          minAngle, 0);
        }
        b->handR.pos = func_0041B898(&b->foreR);
    }
    if (p->handMode != 1) {
        Vec axis = func_0041B9E0(&b->foreL);
        Vec hand = func_0041B9E0(&b->handL);
        Vec pos = func_0041B898(&b->handL);
        Quat q;
        func_004887D8(&q, &hand, &axis);
        b->handL.rot = q * b->handL.rot;
        Vec x = func_00421DC0(&b->handL.rot);
        setRot(&q, x, Angle(bendL));
        b->handL.rot = q * b->handL.rot;
        Vec end = func_0041B898(&b->handL);
        pos = pos - end + b->handL.pos;
        {
            Angle minAngle(Degree(5.0f));
            func_00420510(&flag, &b->upperL, &b->foreL, func_0041B9D8(&b->upperL), func_0041B9D8(&b->foreL), &poleL,
                          &endL, &pos, &D_00622B00, &D_00622B40, 0x1.47ae14p-6f,
                          minAngle, 0);
        }
        b->handL.pos = func_0041B898(&b->foreL);
    }
    if (p->handMode != 1) {
        Vec axis = func_0041B9E0(&b->foreR);
        Vec hand = func_0041B9E0(&b->handR);
        Vec pos = func_0041B898(&b->handR);
        Quat q;
        func_004887D8(&q, &hand, &axis);
        b->handR.rot = q * b->handR.rot;
        Vec x = func_00421DC0(&b->handR.rot);
        setRot(&q, x, Angle(bendR));
        b->handR.rot = q * b->handR.rot;
        Vec end = func_0041B898(&b->handR);
        pos = pos - end + b->handR.pos;
        {
            Angle minAngle(Degree(5.0f));
            func_00420510(&flag, &b->upperR, &b->foreR, func_0041B9D8(&b->upperR), func_0041B9D8(&b->foreR), &poleR,
                          &endR, &pos, &D_00622B30, &D_00622B40, 0x1.47ae14p-6f,
                          minAngle, 0);
        }
        b->handR.pos = func_0041B898(&b->foreR);
    }
    if (p->twistL != 0.0f) {
        Quat q = b->handL.rot;
        turn(&q, func_0041B9E0(&b->handL), Angle(p->twistL));
        b->handL.rot = q;
    }
    if (p->twistR != 0.0f) {
        Quat q = b->handR.rot;
        turn(&q, func_0041B9E0(&b->handR), Angle(-p->twistR));
        b->handR.rot = q;
    }
    {
        Quat hand = b->handL.rot, fore = b->foreL.rot, upper = b->upperL.rot, shoulder = b->shoulderL.rot;
        Vec axisF = func_0041B9E0(&b->foreL);
        Vec axisU = func_0041B9E0(&b->upperL);
        Vec axisS = func_0041B9E0(&b->shoulderL);
        Angle tf = func_00423AA0(&func_00421D88(&fore), &func_00421D88(&hand), &axisF);
        /* computed but unused: dropping the named results changes the frame */
        /* computed but unused: dropping the named results changes the frame */
        Angle tu = func_00423AA0(&func_00421D88(&upper), &func_00421D88(&fore), &axisU);
        Angle ts = func_00423AA0(&func_00421D88(&shoulder), &func_00421D88(&upper), &axisS);
        if (p->fixedL) {
            bool over = tf.a > PI_2;
            if (over) tf.a -= 0x1.921fb4p+2f;
        }
        turn(&fore, axisF, tf * 0x1.666666p-1f);
        b->foreL.rot = fore;
        turn(&upper, axisU, tf * 0.25f);
        b->upperL.rot = upper;
    }
    {
        Quat hand = b->handR.rot, fore = b->foreR.rot, upper = b->upperR.rot, shoulder = b->shoulderR.rot;
        Vec axisF = func_0041B9E0(&b->foreR);
        Vec axisU = func_0041B9E0(&b->upperR);
        Vec axisS = func_0041B9E0(&b->shoulderR);
        Angle tf = func_00423AA0(&func_00421D88(&fore), &func_00421D88(&hand), &axisF);
        /* computed but unused: dropping the named results changes the frame */
        /* computed but unused: dropping the named results changes the frame */
        Angle tu = func_00423AA0(&func_00421D88(&upper), &func_00421D88(&fore), &axisU);
        Angle ts = func_00423AA0(&func_00421D88(&shoulder), &func_00421D88(&upper), &axisS);
        if (p->fixedR) {
            bool under = tf.a < -PI_2;
            if (under) tf.a += 0x1.921fb4p+2f;
        }
        turn(&fore, axisF, tf * 0x1.54fdf2p-1f);
        b->foreR.rot = fore;
        turn(&upper, axisU, tf * 0x1.54fdf2p-2f);
        b->upperR.rot = upper;
    }
    res->reachedL = flag;
    res->reachedR = flag;
    return 1;
}
