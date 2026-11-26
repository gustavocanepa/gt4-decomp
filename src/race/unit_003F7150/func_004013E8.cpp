/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * func_004013E8 (inferred): per-frame update of a driver animation controller (sibling of
 * func_00401148, which initialises the same channels). It copies the parameter block at +0x160 to
 * +0x260, then steps each channel stored behind the handle: five damped springs (position and
 * velocity read with the 0x40CDxx getters, integrated over the car's dt, clamped, written back
 * with the 0x40CExx/0x40CFxx setters) driven by a speed-dependent coefficient, the steering input
 * and two parameter readers; two 0..1 ramps; a gear-change pump; and a sideways sway toward the
 * nearest other car in the race (its direction against the car's heading turned a quarter turn).
 *
 * Source shape notes (each decides register or schedule order, see knowledge/attempts.jsonl):
 * - the spring position is written through a volatile pointer, so its store/reload pairs stay;
 * - each clamp handles the velocity first and re-reads the position through `px`: that read has
 *   to wait for the velocity store, which is the original's allocation of the two clamps;
 * - `mine` is read through a pointer taken where it is declared, one component at a time;
 * - one `rate` for both sway arms, initialised to 0 before the tests.
 */
typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec {
    float x, y, z, w;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec(const Vec &v) { *(u128 *)this = *(const u128 *)&v; }
    Vec &operator=(const Vec &v) { *(u128 *)this = *(const u128 *)&v; return *this; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    float &X() { return x; }
    float &Y() { return y; }
    float &Z() { return z; }
    Vec &operator-=(const Vec &v) { X() -= v.x; Y() -= v.y; Z() -= v.z; return *this; }
    Vec operator-(const Vec &v) { Vec r = *this; r -= v; return r; }
    Vec &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    Vec operator*(float s) { Vec r = *this; r *= s; return r; }
    float lengthSq() { return X() * X() + Y() * Y() + Z() * Z(); }
    float dot(Vec &v) { return X() * v.X() + Y() * v.Y() + Z() * v.Z(); }
} __attribute__((aligned(16)));

struct Mat3;
extern "C" void func_00425348(Mat3 *, const float *);
struct Mat3 { float m[9]; Mat3() {} Mat3(const float *a) { func_00425348(this, a); } };
extern "C" void func_00489300(Vec *, const Mat3 *, const Vec *);
struct Scalar { float v; Scalar(float f) : v(f) {} } __attribute__((aligned(16)));
static inline Mat3 rotY(const Scalar &a) { return Mat3(&a.v); }
static inline Vec operator*(const Mat3 &m, const Vec &v) { Vec r; func_00489300(&r, &m, &v); return r; }

struct Car {
    char pad0[4];
    void *race;
    char pad8[0x544 - 8];
    unsigned char id;
    char pad545[0x54C - 0x545];
    float dt;
    char pad550[0x648 - 0x550];
    float dir[3];
    char pad654[0x6C8 - 0x654];
    float speed;
};

struct Race {
    char pad[0xF8A0];
    int count;
};

struct Ctrl { char pad0[0x160]; char params[0x100]; char prev[0x100]; };

struct Pair { float a, b; };

extern "C" {
float func_0035A540(Car *, int);
int func_0035A478(Car *, int);
float func_003446A0(Car *);
float func_00401048(Car *) throw();
float func_00344798(Car *, float);
float func_003447F8(Car *, float);
float func_00344828(Car *, float);
float func_00344888(Car *, float);
Car *func_0034C190(void *, int);
void func_00406E98(void **, Car *, float);
void func_00407208(void *, void *);
void func_0040CD18(void **, void *);
float func_0040CD20(void **);
float func_0040CD30(void **);
float func_0040CD50(void **);
float func_0040CD60(void **);
float func_0040CD70(void **);
float func_0040CD80(void **);
float func_0040CD90(void **);
float func_0040CDA0(void **);
float func_0040CDB0(void **);
float func_0040CDC0(void **);
float func_0040CDD0(void **);
float func_0040CDE0(void **);
float func_0040CDF0(void **);
float func_0040CE00(void **);
float func_0040CE70(void **);
float func_0040CE80(void **);
float func_0040CE90(void **);
float func_0040CEA0(void **);
float func_0040CEB0(void **);
float func_0040D068(void **, Car *);
void func_0040CEC0(void **, float);
void func_0040CED0(void **, float);
void func_0040CEE0(void **, float);
void func_0040CEF0(void **, float);
void func_0040CF00(void **, float);
void func_0040CF10(void **, float);
void func_0040CF20(void **, float);
void func_0040CF30(void **, float);
void func_0040CF40(void **, float);
void func_0040CF50(void **, float);
void func_0040CF60(void **, float);
void func_0040CF70(void **, float);
void func_0040CF80(void **, float);
void func_0040CF90(void **, float);
void func_0040CFA0(void **, float);
void func_0040D018(void **, float);
void func_0040D028(void **, float);
void func_0040D038(void **, float);
void func_0040D048(void **, float);
void func_0040D058(void **, float);
}

static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float mx(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "0"(a), "f"(b)); return r; }
static inline float mn(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float mn0(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "0"(a), "f"(b)); return r; }
static inline float mxp(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float rsqrt(float a, float b) { float r; __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline void init(Pair *p, float x0, float y0, float x1, float y1) { p->a = (y1 - y0) / (x1 - x0); p->b = 0x1.79435cp-1f; }
static inline float eval(Pair *p, float x) { return p->a * x + p->b; }
static inline float clamp(float *lo, float *hi, float x) { x = mx(x, *lo); return mn(x, *hi); }
static inline float clampv(float x, float lo, float hi) { return mn(mx(x, lo), hi); }

/* one spring channel's state, read from and written back to the handle around each update */
struct Spring {
    float v, x;   /* velocity, position */
};

static inline void spring(float *pv, volatile float *px, float x, float v, float target, float k, float c, float dt) {
    *pv += ((target - x) * k - v * c) * dt;
    (void)(*px += *pv * dt);
}

extern "C" void func_004013E8(Ctrl *self, Car *car) {
    void *handle;
    Pair coeff;
    Spring st;
    void *src = self->params;
    void *dst = self->prev;
    func_0040CD18(&handle, src);
    func_00407208(dst, src);
    init(&coeff, 1.0f, 0.75f, 20.0f, 1.0f);
    float speed = car->speed * 60.0f * 60.0f * 0x1.0624dcp-10f;
    int myId = car->id;
    float dt = car->dt;
    float a = func_0035A540(car, 2);
    float b = func_0035A540(car, 3);
    float c = func_003446A0(car);
    float d = func_00401048(car);
    st.v = 0.75f;
    st.x = 1.0f;
    float *pv = &st.v;
    float x;
    volatile float *px = &st.x;
    float f = clamp(pv, &st.x, eval(&coeff, speed)) * d;

    st.x = func_0040CD20(&handle);
    st.v = func_0040CD30(&handle);
    spring(pv, px, st.x, st.v, f * 0x1.999998p-3f, 0x1.7bfffep+8f, 40.0f, dt);
    {
        float v = mx(*pv, -1.0f);
        v = mn0(v, 1.0f);
        st.v = v;
        float t = mx(*(float *)px, -0x1.999998p-3f);
        x = mn(t, 0x1.999998p-3f);
        st.x = x;
    }
    func_0040CEE0(&handle, f);
    func_0040CEC0(&handle, st.x);
    func_0040CED0(&handle, st.v);

    st.x = func_0040CDF0(&handle);
    st.v = func_0040CE00(&handle);
    spring(pv, px, st.x, st.v, f * 0.5f, 0x1.28dffep+11f, 100.0f, dt);
    {
        float v = mx(*pv, -1.0f);
        v = mn0(v, 1.0f);
        st.v = v;
        float t = mx(*(float *)px, -0.5f);
        x = mn(t, 0.5f);
        st.x = x;
    }
    func_0040CF90(&handle, st.x);
    func_0040CFA0(&handle, st.v);

    st.x = func_0040CD50(&handle);
    if (b < st.x) {
        x = st.x + dt * -2.0f;
        float level = clampv(x, 0.0f, 1.0f);
        st.x = x;
        func_0040CEF0(&handle, level);
    } else {
        func_0040CEF0(&handle, b);
    }

    st.x = func_0040CD60(&handle);
    st.v = func_0040CD70(&handle);
    spring(pv, px, st.x, st.v, c, 0x1.0dffe4p+2f, 7.5f, dt);
    {
        float v = mx(*pv, -2.0f);
        v = mn0(v, 2.0f);
        st.v = v;
        float t = mx(*(float *)px, 0.0f);
        x = mn(t, 1.0f);
        st.x = x;
    }
    func_0040CF00(&handle, st.x);
    func_0040CF10(&handle, st.v);

    st.x = func_0040CDA0(&handle);
    if (a < st.x) {
        x = st.x + dt * -2.0f;
        float level = clampv(x, 0.0f, 1.0f);
        st.x = x;
        func_0040CF40(&handle, level);
    } else {
        func_0040CF40(&handle, a);
    }

    {
        float p = func_0040CD80(&handle);
        float v = func_0040CD90(&handle);
        int gear = func_0035A478(car, 0);
        if (gear == 1 || gear == -1)
            v = 8.0f;
        p += v * dt;
        if (p >= 1.0f) {
            v = -6.0f;
            p = 1.0f;
        } else if (p < 0.0f) {
            v = 0.0f;
            p = v;
        }
        func_0040CF20(&handle, p);
        func_0040CF30(&handle, v);
    }

    st.x = func_0040CDB0(&handle);
    {
        float rate = absf(speed) < 1.0f ? 3.0f : -3.0f;
        x = st.x + rate * dt;
        float level = clampv(x, 0.0f, 1.0f);
        st.x = x;
        func_0040CF50(&handle, level);
    }

    st.x = func_0040CDC0(&handle);
    {
        float rate;
        if (0x1.0c152p-2f < absf(func_00344888(car, 0.0f)) && speed < 180.0f)
            rate = 0x1.333332p-1f;
        else
            rate = -0x1.999998p-3f;
        x = st.x + rate * dt;
        float level = clampv(x, 0.0f, 1.0f);
        st.x = x;
        func_0040CF60(&handle, level);
    }

    st.x = func_0040CDD0(&handle);
    st.v = func_0040CDE0(&handle);
    spring(pv, px, st.x, st.v, func_0040CDC0(&handle), 0x1.2ffffcp+10f, 80.0f, dt);
    {
        float v = mx(*pv, -1.0f);
        v = mn0(v, 1.0f);
        st.v = v;
        float t = mx(*(float *)px, 0.0f);
        x = mn(t, 1.0f);
        st.x = x;
    }
    func_0040CF70(&handle, st.x);
    func_0040CF80(&handle, st.v);

    st.x = func_0040CE70(&handle);
    st.v = func_0040CE80(&handle);
    spring(pv, px, st.x, st.v, absf(func_0040D068(&handle, car)), 0x1.7bfffep+3f, 10.0f, dt);
    {
        float v = mx(*pv, -1.0f);
        v = mn0(v, 1.0f);
        st.v = v;
        float t = mx(*(float *)px, 0.0f);
        x = mn(t, 1.0f);
        st.x = x;
    }
    func_0040D018(&handle, x);
    func_0040D028(&handle, st.v);

    func_00406E98(&handle, car, dt);
    Race *race = (Race *)car->race;
    st.x = func_0040CE90(&handle);
    float sway = func_0040CEA0(&handle);
    float swayVel = func_0040CEB0(&handle);
    float p34 = func_0040CDF0(&handle);
    float p38 = func_0040CE00(&handle);
    if (swayVel == 0.0f && 40.0f < speed && race != 0) {
        Vec mine;
        float *pm = &mine.x;
        mine.x = func_00344798(car, 0.0f);
        mine.y = func_003447F8(car, 0.0f);
        mine.z = func_00344828(car, 0.0f);
        float best = 0.0f;
        int bestId = -1;
        for (int i = 0; i < race->count; i++) {
            Car *other = func_0034C190(race, i);
            int id = other->id;
            if (id != myId) {
                Vec there;
                there.x = func_00344798(other, 0.0f);
                there.y = func_003447F8(other, 0.0f);
                there.z = func_00344828(other, 0.0f);
                Vec dlt = mine - there;
                float dist = dlt.lengthSq();
                if (bestId == -1 || dist < best) {
                    best = dist;
                    bestId = id;
                }
            }
        }
        if (bestId != -1) {
            Car *other = func_0034C190(race, bestId);
            Vec to;
            Vec t;
            Vec fwd;
            float &fx = fwd.X();
            to.X() = func_00344798(other, 0.0f);
            to.Y() = func_003447F8(other, 0.0f);
            to.Z() = func_00344828(other, 0.0f);
            to.X() -= pm[0];
            float my = pm[1];
            to.Y() -= my;
            float mz = pm[2];
            to.Z() -= mz;
            float *dir = car->dir;
            t.set(dir[0], dir[2], -dir[1]);
            fx = t.x;
            fwd.Y() = t.y;
            fwd.Z() = t.z;
            float lt = to.lengthSq();
            float lf = fwd.lengthSq();
            if (0x1.47ae1p-7f < lt && 0x1.47ae1p-7f < lf) {
                to = to * rsqrt(1.0f, lt);
                fwd = fwd * rsqrt(1.0f, lf);
                if (to.dot(fwd) < 0.0f) {
                    if (lt < 225.0f) {
                        x = st.x + dt;
                        (void)(*px = x);
                    } else if (lt < 625.0f) {
                        x = st.x + dt * 0.5f;
                        (void)(*px = x);
                    } else if (6400.0f < lt) {
                        x = st.x - dt * 0.5f;
                        (void)(*px = x);
                    }
                    x = mxp(-4.0f, st.x);
                    (void)(*px = x);
                }
            }
            x = st.x;
            if (0.0f < x) {
                Vec side;
                Vec &s = side;
                const Mat3 &m = rotY(Scalar(0x1.921fb4p+0f));
                s = m * to;
                if (0.0f < s.dot(fwd))
                    swayVel = -0x1.fffffep-2f;
                else
                    swayVel = 0x1.fffffep-2f;
                if (p38 * swayVel < 0.0f || 0x1.ccccccp-3f < absf(p34)) {
                    st.x = -0x1.999998p-2f;
                    swayVel = 0.0f;
                } else {
                    st.x = -4.0f;
                }
            }
        }
    }
    x = st.x;
    float rate = 0.0f;
    if (0.0f < swayVel) {
        rate = sway < 0.5f ? 7.0f : -0x1.0ccccap+3f;
        swayVel += rate * dt;
        if (swayVel < 0x1.333332p-2f)
            swayVel = 0x1.333332p-2f;
    } else if (swayVel < 0.0f) {
        rate = -0.5f < sway ? -7.0f : 0x1.0ccccap+3f;
        swayVel += rate * dt;
        if (-0x1.333332p-2f < swayVel)
            swayVel = -0x1.333332p-2f;
    }
    if (1.0f < sway || sway < -1.0f) {
        swayVel = 0.0f;
        sway = swayVel;
    }
    sway += swayVel * dt;
    func_0040D038(&handle, x);
    func_0040D048(&handle, sway);
    func_0040D058(&handle, swayVel);
}
