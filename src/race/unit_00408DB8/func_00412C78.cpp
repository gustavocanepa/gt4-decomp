/* compiler: ee-gcc2.96-no-strict-aliasing */
/* func_00412C78 (inferred): per-frame state machine of a driver's hand on the gear lever and the
 * wheel (sibling of func_00412018, same Obj/St idioms). Three spring channels a, b, c are released,
 * moved towards 0.5 (func_004145C8 shapes the speed), parked, and pulled back; the gear channel
 * (func_00412BF0(gear)), the side channel (func_00412C30(side)) and the shift-lever channel
 * (5 degrees while shifting == 1) are chased by a damped spring limited to pi/2 per second, and
 * a hold timer from DRIVERSUPPORT::GetMotoristDynamicParameter decides when to let go. The state
 * numbers (0..39, stored behind func_00385F70) and the channel roles are guesses from the control
 * flow; the blend value behind func_00385E58 runs 0..3 between the three hand positions. */
typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Car { char pad[0x624]; u8 f624; };
struct Obj {
    s32 f0;
    char pad4[4];
    s32 f8;
    s32 *fC;
    s32 f10;
    void *f14;
    Car *f18;
    char pad1C[0x110 - 0x1C];
    f32 dt;
};

struct St { f32 acc; f32 *vel; f32 *pos; };

extern "C" s32 func_0040CCD8(Car *);
extern "C" s32 *func_00385FB0(s32 *);
extern "C" void func_00385FD0(s32 *, s32);
extern "C" void func_00385FE0(s32 *, s32);
extern "C" void func_00385FF0(s32 *, s32);
extern "C" void func_00386000(s32 *, s32);
extern "C" void func_00386010(s32 *, s32);
extern "C" void func_00386020(s32 *, s32);
extern "C" s32 func_00385ED0(s32);
extern "C" s32 func_00385F00(s32 *);
extern "C" s32 func_00385F30(s32 *);
extern "C" s32 func_00385F50(s32 *);
extern "C" s32 *func_00385F70(s32 *);
extern "C" s32 *func_00386138(s32 *);
extern "C" f32 *func_00385B48(s32);
extern "C" f32 *func_00385B58(s32);
extern "C" f32 *func_00385B68(s32);
extern "C" f32 *func_00385B98(s32);
extern "C" f32 *func_00385DD8(s32);
extern "C" f32 *func_00385DE8(s32);
extern "C" f32 *func_00385DF8(s32);
extern "C" f32 *func_00385E18(s32);
extern "C" f32 *func_00385E28(s32);
extern "C" f32 *func_00385E38(s32);
extern "C" f32 *func_00385E58(s32);
extern "C" f32 *func_00386228(s32);
extern "C" f32 *func_00386248(s32);
extern "C" f32 *func_00386368(s32);
extern "C" f32 *func_00386528(s32);
extern "C" f32 *func_00386538(s32);
extern "C" f32 *func_00386548(s32);
extern "C" f32 *func_00386558(s32);
extern "C" f32 func_00412BF0(s32);
extern "C" f32 func_00412C30(s32);
extern "C" f32 func_004145C8(f32, f32);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
extern "C" f32 func_0044F910(void *);

#define DEG1 0x1.1df468p-6f
#define DEG5 0x1.657182p-4f

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 clampf(f32 v, f32 lo, f32 hi) { return minf(maxf(v, lo), hi); }
static inline f32 absf(f32 x) { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

static inline void init(St *s, f32 *v, f32 *p) { s->acc = 0.0f; s->vel = v; s->pos = p; }
static inline void fix(St *s, f32 a, f32 v, f32 p) { s->acc = a; *s->vel = v; *s->pos = p; }
static inline void stop(St *s, f32 a, f32 v) { s->acc = a; *s->vel = v; }
static inline void integrate(St *s, f32 dt) { *s->vel += s->acc * dt; *s->pos += *s->vel * dt; s->acc = 0.0f; }
/* drives a channel towards target with a damped spring, speed limited to pi/2 per second
 * (the spring of func_00413FC8) */
static inline void approach(St *s, f32 *vel, f32 *pos, f32 target, f32 dt) {
    s->acc += (target - *pos) * 100.0f;
    s->acc -= *vel * 20.0f;
    f32 v = *vel + s->acc * dt;
    *vel = v;
    f32 lim = 0x1.921fb4p+0f;
    if (v * v > 2.4674008f) {
        if (v > 0.0f) {
            *vel = lim;
        } else {
            *vel = -lim;
        }
    }
    *s->pos += *s->vel * dt;
    s->acc = 0.0f;
}
/* the same spring for the shift-lever channel; its clamp stores through a pointer the negative
 * arm sets again, which is how the original keeps a copy of vel for the positive arm */
static inline void approachLever(St *s, f32 *vel, f32 *pos, f32 target, f32 dt) {
    s->acc += (target - *pos) * 100.0f;
    s->acc -= *vel * 20.0f;
    f32 v = *vel + s->acc * dt;
    *vel = v;
    f32 lim = 0x1.921fb4p+0f;
    f32 *p = vel;
    if (v * v > 2.4674008f) {
        if (v > 0.0f) {
            *p = lim;
        } else {
            p = vel;
            *p = -lim;
        }
    }
    *s->pos += *s->vel * dt;
    s->acc = 0.0f;
}

extern "C" void func_00412C78(Obj *animation) {
    u8 gear = animation->f18->f624;
    s32 side = func_0040CCD8(animation->f18);
    if (*func_00385FB0(animation->fC) == 1) {
        func_00385FD0(animation->fC, gear);
        func_00386010(animation->fC, side);
        *func_00385B68(animation->f0) = func_00412BF0(gear);
        *func_00385DE8(animation->f0) = func_00412C30(side);
    }
    s32 targetGear = func_00385ED0(*animation->fC);
    s32 targetSide = func_00385F50(animation->fC);
    if (gear != targetGear) *func_00386138(animation->fC) = 1;
    else *func_00386138(animation->fC) = 0;
    s32 shifting = *func_00386138(animation->fC);
    s32 wasShifting = func_00385F30(animation->fC);
    func_00385FE0(animation->fC, gear);
    func_00386020(animation->fC, side);
    func_00386000(animation->fC, shifting);
    St a, b, c;
    init(&a, func_00386228(animation->f8), func_00385B48(animation->f0));
    init(&b, func_00386528(animation->f8), func_00385DD8(animation->f0));
    init(&c, func_00386548(animation->f8), func_00385E18(animation->f0));
    *func_00385B98(animation->f0) = 0.0f;
    *func_00385B58(animation->f0) = 0.0f;

    switch (func_00385F00(animation->fC)) {
    case 0:
        fix(&a, 0.0f, 0.0f, 0.0f);
        fix(&b, 0.0f, 0.0f, 0.0f);
        if (shifting != wasShifting) {
            *func_00385F70(animation->fC) = 27;
            *func_00385E58(animation->f0) = 2.0f;
        } else if (gear != targetGear) {
            *func_00385F70(animation->fC) = 1;
            *func_00385E58(animation->f0) = 0.0f;
        } else if (side != targetSide) {
            *func_00385F70(animation->fC) = 14;
            *func_00385E58(animation->f0) = 1.0f;
        }
        break;
    case 1:
        {
            f32 p = *a.pos;
            if (0.5f < p) fix(&a, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            else stop(&a, 0.0f, 0.0f);
        }
        *func_00385F70(animation->fC) = 3;
    case 3:
        if (gear == targetGear) {
            *func_00385F70(animation->fC) = 8;
            break;
        }
        *a.vel = func_004145C8(*a.pos * 2.0f, 0x1.999998p-1f);
        integrate(&a, animation->dt);
        if (*a.pos < 0.5f) break;
        fix(&a, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 6;
        break;
    case 6: {
        St d;
        St *s = &d;
        f32 *vel = func_00386248(animation->f8);
        f32 *pos = func_00385B68(animation->f0);
        init(s, vel, pos);
        f32 target = func_00412BF0(gear);
        approach(&d, vel, pos, target, animation->dt);
        if (absf(target - *func_00385B68(animation->f0)) < DEG1) {
            fix(&d, 0.0f, 0.0f, target);
            func_00385FD0(animation->fC, gear);
            *func_00385F70(animation->fC) = 7;
            *func_00386368(animation->f8) = 0.0f;
        }
        break;
    }
    case 7:
        if (shifting != wasShifting) {
            *func_00385F70(animation->fC) = 12;
            *func_00385E58(animation->f0) = 0.0f;
        } else if (side != targetSide) {
            *func_00385F70(animation->fC) = 10;
            *func_00385E58(animation->f0) = 0.0f;
        } else {
            *func_00386368(animation->f8) += animation->dt;
            if (*func_00386368(animation->f8) < func_0044F910(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter())) break;
            *func_00385F70(animation->fC) = 8;
        }
        break;
    case 8:
        {
            f32 p = *a.pos;
            if (p < 0.5f) fix(&a, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            else stop(&a, 0.0f, 0.0f);
        }
        *func_00385F70(animation->fC) = 9;
    case 9:
        *a.vel = func_004145C8(*a.pos * 2.0f - 1.0f, 0x1.999998p-1f);
        integrate(&a, animation->dt);
        if (gear != targetGear) {
            *func_00385F70(animation->fC) = 1;
            break;
        }
        if (*a.pos < 1.0f) break;
        *func_00385F70(animation->fC) = 0;
        fix(&a, 0.0f, 0.0f, 0.0f);
        break;
    case 10:
        fix(&b, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 11;
    case 11:
        *func_00385E58(animation->f0) += animation->dt * 2.0f;
        if (!(1.0f <= *func_00385E58(animation->f0))) break;
        *func_00385E58(animation->f0) = 1.0f;
        *func_00385F70(animation->fC) = 14;
        fix(&a, 0.0f, 0.0f, 0.0f);
        break;
    case 23:
        fix(&a, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 24;
    case 24:
        *func_00385E58(animation->f0) -= animation->dt * 2.0f;
        if (!(*func_00385E58(animation->f0) <= 0.0f)) break;
        *func_00385E58(animation->f0) = 0.0f;
        *func_00385F70(animation->fC) = 1;
        fix(&b, 0.0f, 0.0f, 0.0f);
        break;
    case 12:
        fix(&c, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 13;
        *func_00385E58(animation->f0) = 3.0f;
    case 13:
        *func_00385E58(animation->f0) -= animation->dt * 2.0f;
        if (!(*func_00385E58(animation->f0) <= 2.0f)) break;
        *func_00385E58(animation->f0) = 2.0f;
        *func_00385F70(animation->fC) = 27;
        fix(&a, 0.0f, 0.0f, 0.0f);
        break;
    case 36:
        fix(&a, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 37;
    case 37:
        *func_00385E58(animation->f0) += animation->dt * 2.0f;
        if (!(3.0f <= *func_00385E58(animation->f0))) break;
        *func_00385E58(animation->f0) = 0.0f;
        *func_00385F70(animation->fC) = 1;
        fix(&c, 0.0f, 0.0f, 0.0f);
        break;
    case 25:
        fix(&c, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 26;
    case 26:
        *func_00385E58(animation->f0) += animation->dt * 2.0f;
        if (!(2.0f <= *func_00385E58(animation->f0))) break;
        *func_00385E58(animation->f0) = 2.0f;
        *func_00385F70(animation->fC) = 27;
        fix(&b, 0.0f, 0.0f, 0.0f);
        break;
    case 38:
        fix(&b, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 39;
    case 39:
        *func_00385E58(animation->f0) -= animation->dt * 2.0f;
        if (!(*func_00385E58(animation->f0) <= 1.0f)) break;
        *func_00385E58(animation->f0) = 1.0f;
        *func_00385F70(animation->fC) = 14;
        fix(&c, 0.0f, 0.0f, 0.0f);
        break;
    case 14:
        {
            f32 p = *b.pos;
            if (0.5f < p) fix(&b, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            else stop(&b, 0.0f, 0.0f);
        }
        *func_00385F70(animation->fC) = 16;
    case 16:
        if (side == targetSide) {
            *func_00385F70(animation->fC) = 21;
            break;
        }
        *b.vel = func_004145C8(*b.pos * 2.0f, 0x1.999998p-1f);
        integrate(&b, animation->dt);
        if (*b.pos < 0.5f) break;
        fix(&b, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 19;
        break;
    case 19: {
        St d;
        St *s = &d;
        f32 *vel = func_00386538(animation->f8);
        f32 *pos = func_00385DE8(animation->f0);
        init(s, vel, pos);
        f32 target = func_00412C30(side);
        approach(&d, vel, pos, target, animation->dt);
        if (absf(target - *func_00385DE8(animation->f0)) < DEG1) {
            fix(&d, 0.0f, 0.0f, target);
            func_00386010(animation->fC, side);
            *func_00385F70(animation->fC) = 20;
            *func_00386368(animation->f8) = 0.0f;
        }
        break;
    }
    case 20:
        if (shifting != wasShifting) {
            *func_00385F70(animation->fC) = 25;
            *func_00385E58(animation->f0) = 1.0f;
        } else if (gear != targetGear) {
            *func_00385F70(animation->fC) = 23;
            *func_00385E58(animation->f0) = 1.0f;
        } else {
            *func_00386368(animation->f8) += animation->dt;
            if (*func_00386368(animation->f8) < func_0044F910(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter())) break;
            *func_00385F70(animation->fC) = 21;
        }
        break;
    case 21:
        {
            f32 p = *b.pos;
            if (p < 0.5f) fix(&b, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            else stop(&b, 0.0f, 0.0f);
        }
        *func_00385F70(animation->fC) = 22;
    case 22:
        *b.vel = func_004145C8(*b.pos * 2.0f - 1.0f, 0x1.999998p-1f);
        integrate(&b, animation->dt);
        if (side != targetSide) {
            *func_00385F70(animation->fC) = 14;
            break;
        }
        if (*b.pos < 1.0f) break;
        *func_00385F70(animation->fC) = 0;
        fix(&b, 0.0f, 0.0f, 0.0f);
        break;
    case 27:
        {
            f32 p = *c.pos;
            if (0.5f < p) fix(&c, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            else stop(&c, 0.0f, 0.0f);
        }
        *func_00385F70(animation->fC) = 29;
    case 29:
        if (shifting == wasShifting) {
            *func_00385F70(animation->fC) = 34;
            break;
        }
        *c.vel = func_004145C8(*c.pos * 2.0f, 0x1.999998p-1f);
        integrate(&c, animation->dt);
        if (*c.pos < 0.5f) break;
        fix(&c, 0.0f, 0.0f, 0.5f);
        *func_00385F70(animation->fC) = 32;
        break;
    case 32: {
        St d;
        St *s = &d;
        f32 *vel = func_00386558(animation->f8);
        f32 *pos = func_00385E28(animation->f0);
        init(s, vel, pos);
        f32 target = 0.0f;
        if (shifting == 1) target = DEG5;
        approachLever(&d, vel, pos, target, animation->dt);
        if (absf(target - *func_00385E28(animation->f0)) < DEG1) {
            fix(&d, 0.0f, 0.0f, target);
            func_00385FF0(animation->fC, shifting);
            *func_00385F70(animation->fC) = 33;
            *func_00386368(animation->f8) = 0.0f;
        }
        break;
    }
    case 33:
        if (gear != targetGear) {
            *func_00385F70(animation->fC) = 36;
            *func_00385E58(animation->f0) = 2.0f;
        } else if (side != targetSide) {
            *func_00385F70(animation->fC) = 38;
            *func_00385E58(animation->f0) = 2.0f;
        } else {
            *func_00386368(animation->f8) += animation->dt;
            if (*func_00386368(animation->f8) < func_0044F910(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter())) break;
            *func_00385F70(animation->fC) = 34;
        }
        break;
    case 34:
        {
            f32 p = *c.pos;
            if (p < 0.5f) fix(&c, 0.0f, 0.0f, clampf(1.0f - p, 0.0f, 1.0f));
            else stop(&c, 0.0f, 0.0f);
        }
        *func_00385F70(animation->fC) = 35;
    case 35:
        *c.vel = func_004145C8(*c.pos * 2.0f - 1.0f, 0x1.999998p-1f);
        integrate(&c, animation->dt);
        if (shifting != wasShifting) {
            *func_00385F70(animation->fC) = 27;
            break;
        }
        if (*c.pos < 1.0f) break;
        *func_00385F70(animation->fC) = 0;
        fix(&c, 0.0f, 0.0f, 0.0f);
        break;
    }
    *func_00385DF8(animation->f0) = *func_00385DE8(animation->f0) / DEG5;
    *func_00385E38(animation->f0) = *func_00385E28(animation->f0) / DEG5;
}
