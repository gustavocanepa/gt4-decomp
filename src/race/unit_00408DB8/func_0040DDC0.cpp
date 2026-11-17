/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Driver head and gaze controller (inferred): a small state machine on the crew member's look mode
 * (glance at a car alongside, check the back mirror, follow a rival, random glances, look into the
 * corner) picks a gaze target, then three spring axes move the head point towards it. The gaze
 * direction is kept at least 60 degrees from straight down: a steeper one is replaced by a vector
 * 30 degrees below the horizon, turned to the target's heading. Field names are inferred from use. */
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec {
    union { u128 q; struct { f32 x, y, z, w; } f; };
    Vec() {}
    Vec(const Vec &v) { q = v.q; }
    Vec &operator=(const Vec &v) { q = v.q; return *this; }
    f32 &operator[](s32 i) { return (&f.x)[i]; }
} __attribute__((aligned(16)));

class CarGeometry {
public:
    virtual s32 GetNumCrew() const;
    virtual f32 GetSeatPosition_X(f32) const;
    virtual f32 GetSeatPosition_Y(f32) const;
    virtual f32 GetSeatPosition_Z(f32) const;
    virtual f32 GetOppositeSeatPosition_X(f32) const;
    virtual f32 GetOppositeSeatPosition_Y(f32) const;
    virtual f32 GetOppositeSeatPosition_Z(f32) const;
    virtual f32 GetStepPosition_X(s32, f32) const;
    virtual f32 GetStepPosition_Y(s32, f32) const;
    virtual f32 GetStepPosition_Z(s32, f32) const;
    virtual f32 GetSteeringWheelCenter_X(f32) const;
    virtual f32 GetSteeringWheelCenter_Y(f32) const;
    virtual f32 GetSteeringWheelCenter_Z(f32) const;
    virtual f32 GetSteeringWheelNormal_X(f32) const;
    virtual f32 GetSteeringWheelNormal_Y(f32) const;
    virtual f32 GetSteeringWheelNormal_Z(f32) const;
    virtual f32 GetSteeringWheelRadius() const;
    virtual f32 GetShiftPosition_X(f32) const;
    virtual f32 GetShiftPosition_Y(f32) const;
    virtual f32 GetShiftPosition_Z(f32) const;
    virtual f32 GetSideBrakePosition_X(f32) const;
    virtual f32 GetSideBrakePosition_Y(f32) const;
    virtual f32 GetSideBrakePosition_Z(f32) const;
    virtual s32 HasBackmirror() const;
    virtual f32 GetBackmirrorPosition_X(f32) const;
    virtual f32 GetBackmirrorPosition_Y(f32) const;
    virtual f32 GetBackmirrorPosition_Z(f32) const;
};

struct Rival { char pad[0x544]; unsigned char id; };
struct World { char pad[0xF8A0]; s32 count; };
struct Car { char pad[4]; World *world; };

/* what func_0040D800 reports about the nearest car */
struct Nearby {
    Vec pos;
    Vec vel;
    Vec f20;
};

struct Head {
    void *a0;               /* 0x00 head point */
    void *a4;
    void *a8;               /* 0x08 gaze state */
    void *ac;               /* 0x0C look mode */
    void *a10;
    CarGeometry *geo;       /* 0x14 */
    Car *car;               /* 0x18 */
    char pad1C[0x30 - 0x1C];
    Vec rot;                /* 0x30 the car's orientation */
    char pad40[0xB0 - 0x40];
    f32 px, py, pz;         /* 0xB0 the car's position */
    char padBC[0xF8 - 0xBC];
    f32 speed;              /* 0xF8 */
    char padFC[0x110 - 0xFC];
    f32 dt;                 /* 0x110 */
    char pad114[0x118 - 0x114];
    f32 steer;              /* 0x118 */
    s32 cockpit;            /* 0x11C */
    s32 fixed;              /* 0x120 */
};

/* one spring axis of the head point */
struct Axis {
    f32 force;
    f32 *vel;
    f32 *pos;
    void init(f32 *v, f32 *p) { force = 0.0f; vel = v; pos = p; }
    void stop() { force = 0.0f; *vel = 0.0f; }
    void place(f32 p) { force = 0.0f; *vel = 0.0f; *pos = p; }
    void pull(f32 target, f32 stiffness) { force += (target - *pos) * stiffness; }
    void step(f32 damping, f32 dt) {
        f32 limit = 7.5f;
        force -= *vel * damping;
        *vel += force * dt;
        if (*vel * *vel > limit * limit) {
            if (*vel > 0.0f) *vel = limit;
            else *vel = -limit;
        }
        *pos += *vel * dt;
        force = 0.0f;
    }
} __attribute__((aligned(16)));

extern "C" {
f32 *func_00385BA8(void *);
f32 *func_00385C58(void *);
f32 *func_00385C68(void *);
f32 *func_00385C78(void *);
s32 *func_00385F80(void *);
s32 *func_00385F90(void *);
s32 *func_00385FB0(void *);
s32 *func_00385FC0(void *);
f32 *func_00386278(void *);
f32 *func_00386288(void *);
f32 *func_00386298(void *);
f32 *func_003863A8(void *);
f32 *func_003863B8(void *);
f32 *func_003863C8(void *);
f32 *func_00386438(void *);
f32 *func_00386448(void *);
f32 *func_00386458(void *);
f32 *func_00386568(void *);
f32 *func_00386578(void *);
s32 func_0040D5C8(Head *);
s32 func_0040D600(Head *);
Rival *func_0040D800(Nearby *, Car *, World *);
s32 func_0040DA48(Vec *, Vec *);
void func_0040DD38(Head *, f32, f32);
Rival *func_0034C190(World *, s32);
s32 func_00350CE8(Car *, Vec *);
f32 func_00344798(void *, f32);
f32 func_003447F8(void *, f32);
f32 func_00344828(void *, f32);
Vec func_00421DF8(const Vec &, f32, f32, f32);
Vec func_00421E50(const Vec &, const Vec &);
f32 *func_00423AA0(f32 *, const Vec *, const Vec *, const Vec *);
void *func_0044F4C0();
f32 func_0044F930(void *);
f32 func_0044F940(void *);
f32 func_0044F950(void *);
f32 func_0044F960(void *);
f32 func_0044F970(void *);
f32 func_0044F980(void *);
f32 func_0044FA00(void *);
f32 func_0044FA10(void *);
f32 func_0044FA20(void *);
s32 func_0044FBE0(void *);
f32 func_0057D118(f32, f32);
f32 func_0057D1F0(f32);
f32 func_0057D2B8(f32);
f32 func_0057D380(f32);
f32 func_0059D2A0(f32);
}
extern Vec D_00622B10;
extern Vec D_00622B50;

static inline f32 absf(f32 x) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline f32 sqrtf_(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline f32 rsqrt(f32 x) { f32 r; __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(1.0f), "f"(x)); return r; }
static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 random01(u32 *seed) {
    *seed = (unsigned long)*seed * 0x0900d309U + 1;
    return (f32)*seed * 0x1p-32f;
}
static inline f32 randomRange(u32 *seed, f32 lo, f32 hi) { return (hi - lo) * random01(seed) + lo; }

static inline f32 lookLimit(Head *h) { return h->cockpit ? func_0044F940(func_0044F4C0()) : func_0044F930(func_0044F4C0()); }
static inline void rivalPosition(Rival *r, Vec &p) {
    p[0] = func_00344798(r, 0.0f);
    p[1] = func_003447F8(r, 0.0f);
    p[2] = func_00344828(r, 0.0f);
}
static inline void scale(Vec &out, Vec v, f32 t) { Vec r(v); r[0] *= t; r.f.y *= t; r.f.z *= t; out = r; }
extern "C" void func_0040DDC0(Head *h, s32 mode, u32 *seed) {
    f32 yaw = 0.0f;
    Axis axes[3];
    axes[0].init(func_00386278(h->a8), func_00385C58(h->a0));
    axes[1].init(func_00386288(h->a8), func_00385C68(h->a0));
    axes[2].init(func_00386298(h->a8), func_00385C78(h->a0));
    s32 prev = *func_00385F80(h->ac);
    Car *car = h->car;
    World *world = car->world;
    Nearby n;
    Rival *near = func_0040D800(&n, car, world);
    if (near) {
        f32 d2 = n.pos[0] * n.pos[0] + n.pos[1] * n.pos[1] + n.pos[2] * n.pos[2];
        s32 passing = 0;
        if (n.pos[2] > 0.0f && h->speed < -11.111111f) {
            f32 rate = h->cockpit ? func_0044F960(func_0044F4C0()) : func_0044F950(func_0044F4C0());
            if (d2 < 225.0f) *func_00386438(h->a8) += rate * h->dt;
            else if (d2 < 625.0f) *func_00386438(h->a8) += rate * 0.5f * h->dt;
            else if (d2 < 6400.0f) *func_00386438(h->a8) -= rate * 0.5f * h->dt;
            if (*func_00386438(h->a8) > 1.0f) {
                if (h->cockpit || func_0040D600(h)) {
                    if (n.pos[0] > 0.0f) *func_00385FC0(h->ac) = 1;
                    else *func_00385FC0(h->ac) = 0;
                    passing = 1;
                    *func_00385F80(h->ac) = 4;
                } else {
                    *func_00386438(h->a8) = 0.95f;
                }
            } else if (*func_00386438(h->a8) < 0.0f) {
                *func_00386438(h->a8) = 0.0f;
            }
        }
        if (passing != 1 && *func_00385F90(h->ac) == -1 && n.pos[2] < 0.0f && n.vel.f.y < -11.111111f
            && d2 > 25.0f && d2 < 625.0f && *func_00386448(h->a8) == 0.0f) {
            *func_00385F90(h->ac) = near->id;
            *func_00385F80(h->ac) = 6;
            *func_00386448(h->a8) = 1.0f;
        }
    }
    if (h->cockpit) {
        if (*func_00385F80(h->ac) == 1 && func_0040D5C8(h)) {
            f32 *p = func_00386458(h->a8);
            *p -= randomRange(seed, 0.1f, 0.25f) * h->dt;
            if (*func_00386458(h->a8) < 0.0f) {
                *func_00385F80(h->ac) = 2;
                *func_00386458(h->a8) = 1.0f;
            }
        } else if (*func_00385F80(h->ac) == 2) {
            f32 *p = func_00386458(h->a8);
            *p -= randomRange(seed, 0.5f, 1.0f) * h->dt;
            if (*func_00386458(h->a8) < 0.0f) {
                *func_00385F80(h->ac) = 1;
                *func_00386458(h->a8) = 1.0f;
            }
        }
    }
    f32 limit = lookLimit(h);
    if (mode != 2) {
        switch (*func_00385F80(h->ac)) {
        case 0:
        case 1:
            if (h->fixed) {
                *func_00385F80(h->ac) = 0;
            } else if (-h->speed < limit) {
                *func_00385F80(h->ac) = 3;
                if (randomRange(seed, 0.0f, 1.0f) < 0.5f) *func_00385FC0(h->ac) = 0;
                else *func_00385FC0(h->ac) = 1;
            } else {
                *func_00385F80(h->ac) = 1;
            }
            break;
        case 3:
            if (limit <= -h->speed) *func_00385F80(h->ac) = 1;
            break;
        case 4: {
            f32 *p = func_00386438(h->a8);
            *p -= func_0044F970(func_0044F4C0()) * h->dt * 0.5f;
            if (*func_00386438(h->a8) < 0.5f) *func_00385F80(h->ac) = 5;
            break;
        }
        case 5: {
            f32 *p = func_00386438(h->a8);
            *p -= func_0044F970(func_0044F4C0()) * h->dt * 0.5f;
            if (*func_00386438(h->a8) < 0.0f) {
                *func_00386438(h->a8) = 0.0f;
                *func_00385F80(h->ac) = 1;
            }
            break;
        }
        case 6: {
            f32 *p = func_00386448(h->a8);
            *p -= func_0044F980(func_0044F4C0()) * h->dt * 0.5f;
            if (*func_00386448(h->a8) < 0.5f) {
                *func_00385F80(h->ac) = 7;
                *func_00385F90(h->ac) = -1;
            }
            break;
        }
        case 7: {
            f32 *p = func_00386448(h->a8);
            *p -= func_0044F980(func_0044F4C0()) * h->dt * 0.5f;
            if (*func_00386448(h->a8) < 0.0f) {
                *func_00386448(h->a8) = 0.0f;
                *func_00385F80(h->ac) = 1;
            }
            break;
        }
        }
    } else {
        *func_00385F80(h->ac) = 1;
    }

    yaw = 0.0f; /* reset again before the gaze switch, as in the original */
    f32 maxYaw = 0.5235987f;
    switch (*func_00385F80(h->ac)) {
    case 0:
    case 1:
    case 5:
    case 7: {
        s32 seen = 0;
        if (func_0044FBE0(func_0044F4C0()) == 1) mode = 1;
        if (*func_00385F80(h->ac) == 0) mode = 1;
        Vec target, d;
        f32 range;
        if (mode == 0) {
            f32 v = absf(*func_00385BA8(h->a0));
            if (v < func_0044FA10(func_0044F4C0())) *func_00386568(h->a8) += h->dt;
            else *func_00386568(h->a8) = 0.0f;
            if (func_00350CE8(h->car, &target) == 0) {
                mode = 1;
            } else {
                seen = 1;
                d[0] = target.f.x - h->px;
                d[1] = target.f.y - h->py;
                d[2] = target.f.z - h->pz;
                d = func_00421E50(h->rot, d);
                f32 angle = func_0057D118(d[0], -d[2]);
                range = func_0044FA00(func_0044F4C0());
                if (absf(angle) < range
                    || (range <= *func_00386578(h->a8) && angle <= -range)
                    || (*func_00386578(h->a8) <= -range && range <= angle)) {
                    *func_00386568(h->a8) = 0.0f;
                } else {
                    f32 *t = func_00386568(h->a8);
                    if (func_0044FA20(func_0044F4C0()) <= *t) mode = 1;
                }
                *func_00386578(h->a8) = angle;
            }
        }
        s32 again;
        do {
            again = 0;
            switch (mode) {
            case 0: {
                Vec e;
                Vec &out = e; /* func_0040DA48's output, addressed before the tests */
                f32 l2 = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
                if (seen && l2 > 0.0f && func_0040DA48(&d, &out)) {
                    f32 flat = sqrtf_(e[0] * e[0] + e[2] * e[2]);
                    f32 eye = h->geo->GetSeatPosition_Y(0.0f) + 0.8f;
                    f32 pitch = func_0057D118(e[1] - eye, flat);
                    if (pitch > 0.26179934f) pitch -= 0.26179934f;
                    else if (pitch < -0.26179934f) pitch += 0.26179934f;
                    else pitch = 0.0f;
                    if (pitch > 0.5235987f) e[1] = 0x1.279a6ap-1f * flat + eye;
                    else if (pitch < -0.5235987f) e[1] = -0x1.279a6ap-1f * flat + eye;
                    else e[1] = func_0057D380(pitch) * flat + eye;
                    *func_003863A8(h->a8) = e[0];
                    *func_003863B8(h->a8) = e[1];
                    *func_003863C8(h->a8) = e[2];
                } else {
                    again = 1;
                    mode = 1;
                }
                break;
            }
            case 2:
                maxYaw = 0.0f;
                /* fall through */
            case 1: {
                f32 s = minf(maxf(h->steer, -maxYaw), maxYaw);
                if (*func_00385F80(h->ac) == 0) s *= 0.1f;
                func_0040DD38(h, s, 0.0f);
                break;
            }
            }
        } while (again);
        break;
    }
    case 3:
    case 4:
        *func_00386568(h->a8) = 0.0f;
        if (h->geo->HasBackmirror()) {
            *func_003863A8(h->a8) = h->geo->GetBackmirrorPosition_X(0.0f);
            *func_003863B8(h->a8) = h->geo->GetBackmirrorPosition_Y(0.0f);
            *func_003863C8(h->a8) = h->geo->GetBackmirrorPosition_Z(0.0f) - 0.5f;
        } else {
            if (*func_00385FC0(h->ac) == 0) yaw = 0x1.921fb4p-1f;
            else if (*func_00385FC0(h->ac) == 1) yaw = -0x1.921fb4p-1f;
            func_0040DD38(h, yaw, 0.0f);
        }
        break;
    case 6:
        for (s32 i = 0; i < world->count; i++) {
            Rival *r = func_0034C190(world, i);
            if (r->id != *func_00385F90(h->ac)) continue;
            Vec d;
            rivalPosition(r, d);
            d[0] -= h->px;
            d[1] -= h->py;
            d[2] -= h->pz;
            d = func_00421DF8(h->rot, d[0], d[1], d[2]);

            f32 l2 = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
            if (l2 > 0.01f) {
                Vec n;
                s32 spare[4]; /* unused; reproduces the original frame layout */
                *func_003863A8(h->a8) = d[0];
                *func_003863B8(h->a8) = d[1];
                *func_003863C8(h->a8) = d[2];
                f32 inv = 1.0f / l2;
                scale(n, d, inv);
                d = n;
                func_00423AA0(&n[0], &D_00622B50, &d, &D_00622B10);
                if (absf(n[0]) > 0x1.41b2f4p-1f) func_0040DD38(h, n[0] > 0.0f ? 0x1.41b2f4p-1f : -0x1.41b2f4p-1f, 0.0f);
            } else {
                func_0040DD38(h, 0.0f, 0.0f);
            }
            break;
        }
        break;
    case 2:
        if (*func_00386458(h->a8) == 1.0f) {
            f32 a = randomRange(seed, -1.0f, 1.0f) * 0x1.921fb4p-1f;
            f32 b = randomRange(seed, -1.0f, 1.0f) * 0x1.41b2f4p-3f;
            func_0040DD38(h, a, b);
        }
        break;
    case 11:
        *func_00385F80(h->ac) = 1;
        break;
    case 10:
        *func_003863A8(h->a8) = h->geo->GetOppositeSeatPosition_X(0.0f);
        *func_003863B8(h->a8) = h->geo->GetOppositeSeatPosition_Y(0.0f) + 0.8f;
        *func_003863C8(h->a8) = h->geo->GetOppositeSeatPosition_Z(0.0f) - 0.5f;
        break;
    }

    if (*func_00385F80(h->ac) != prev) {
        axes[0].stop();
        axes[1].stop();
        axes[2].stop();
    }
    f32 stiffness = h->cockpit ? 25.0f : 50.0f;
    f32 damping = h->cockpit ? 10.0f : 14.14f;
    Vec seat;
    seat.f.x = h->geo->GetSeatPosition_X(0.0f);
    seat.f.y = h->geo->GetSeatPosition_Y(0.0f) + 0.8f;
    seat.f.z = h->geo->GetSeatPosition_Z(0.0f);
    Vec d;
    d.f.x = *func_003863A8(h->a8) - seat.f.x;
    d.f.y = *func_003863B8(h->a8) - seat.f.y;
    d.f.z = *func_003863C8(h->a8) - seat.f.z;
    f32 l2 = d.f.x * d.f.x + d.f.y * d.f.y + d.f.z * d.f.z;
    if (l2 > 0.001f) {
        f32 r = rsqrt(l2);
        d.f.x *= r;
        d.f.y *= r;
        d.f.z *= r;
        f32 tilt = 1.5707963f - func_0059D2A0(-d.f.z);
        if (tilt > 0x1.0c152p+0f) {
            f32 up = 0x1.bb67aep-1f; /* cos 30 */
            f32 c = up;              /* straight down: heading 0, the tilted vector as it is */
            f32 down = -0.5f;        /* -sin 30 */
            if (tilt < 0x1.8da7ep+1f) {
                f32 heading = 1.5707963f - func_0057D118(d.f.y, d.f.x);
                f32 s = func_0057D2B8(heading);
                c = func_0057D1F0(heading);
                d.f.z = down;
                d.f.x = c * 0.0f + s * up;
                d.f.y = -s * 0.0f + c * up;
            } else {
                d.f.x = 0.0f;
                d.f.y = c;
                d.f.z = down;
            }
        }
        d.f.x *= 2.5f;
        d.f.y *= 2.5f;
        d.f.z *= 2.5f;
    } else {
        d.f.x = 0.0f;
        d.f.y = 0.0f;
        d.f.z = -2.5f;
    }
    d.f.x += seat.f.x;
    d.f.y += seat.f.y;
    d.f.z += seat.f.z;
    if (*func_00385FB0(h->ac) == 1) {
        axes[0].place(d.f.x);
        axes[1].place(d.f.y);
        axes[2].place(d.f.z);
        return;
    }
    axes[0].pull(d.f.x, stiffness);
    axes[1].pull(d.f.y, stiffness);
    axes[2].pull(d.f.z, stiffness);
    axes[0].step(damping, h->dt);
    axes[1].step(damping, h->dt);
    axes[2].step(damping, h->dt);
}
