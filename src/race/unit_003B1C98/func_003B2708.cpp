/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Driver posture setup (inferred): fills the posture block and the reference frame of one crew
 * member from the car's geometry (CarGeometry virtuals: seat, step, steering wheel, shift, side
 * brake, fixed handles) and the posture parameters of the seat record, then hands both to
 * func_00416FD8. Returns 1 when a posture was computed. Field meanings are inferred from use. */
typedef int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec {
    union { u128 q; struct { f32 x, y, z, w; } f; };
    Vec() {}
    Vec(const Vec &v) { q = v.q; }
    Vec &operator=(const Vec &v) { q = v.q; return *this; }
    Vec(f32 x, f32 y, f32 z) { f.x = x; f.y = y; f.z = z; }
    Vec(f32 x, f32 y, f32 z, f32 w) { f.x = x; f.y = y; f.z = z; f.w = w; }
    void set(f32 x, f32 y, f32 z) { f.x = x; f.y = y; f.z = z; }
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
    virtual f32 GetChairAngle(f32) const;
    virtual f32 GetShiftBoundingBox_W(f32) const;
    virtual f32 GetShiftBoundingBox_H(f32) const;
    virtual f32 GetSideBrakeLength(f32) const;
    virtual f32 GetShiftLength(f32) const;
    virtual s32 IsManualShift() const;
    virtual f32 GetFixedLeftHandlePosition_X(f32) const;
    virtual f32 GetFixedLeftHandlePosition_Y(f32) const;
    virtual f32 GetFixedLeftHandlePosition_Z(f32) const;
    virtual f32 GetFixedRightHandlePosition_X(f32) const;
    virtual f32 GetFixedRightHandlePosition_Y(f32) const;
    virtual f32 GetFixedRightHandlePosition_Z(f32) const;
    virtual f32 GetFixedLeftHandleVector_X(f32) const;
    virtual f32 GetFixedLeftHandleVector_Y(f32) const;
    virtual f32 GetFixedLeftHandleVector_Z(f32) const;
    virtual f32 GetFixedRightHandleVector_X(f32) const;
    virtual f32 GetFixedRightHandleVector_Y(f32) const;
    virtual f32 GetFixedRightHandleVector_Z(f32) const;
    virtual s32 IsFixedHandle() const;
    virtual s32 IsFixedFoot() const;
    virtual s32 DoesLieOnBelly() const;
};

/* the posture block (func_00416B58 initialises it), 0x360 bytes */
struct Posture {
    f32 grip[2];            /* 0x00, indexed by hand */
    f32 f08, f0C;
    char pad10[0x50 - 0x10];
    f32 f50, f54;
    char pad58[0x5C - 0x58];
    f32 f5C;
    char pad60[0x64 - 0x60];
    f32 f64, f68, f6C;
    char pad70[0x74 - 0x70];
    f32 f74;
    char pad78[0x90 - 0x78];
    f32 v90[3];
    char pad9C[0xBC - 0x9C];
    s32 iBC, iC0;
    char padC4[0xC8 - 0xC4];
    s32 iC8, iCC;
    char padD0[0x200 - 0xD0];
    s32 i200;
    char pad204[0x210 - 0x204];
    f32 f210, f214, f218, f21C;
    f32 f220, f224, f228, f22C;
    f32 f230, f234;
    f32 f238, f23C, f240, f244;
    f32 f248, f24C;
    f32 f250[2], f258[2], f260[2];
    f32 f268, f26C, f270;
    char pad274[0x280 - 0x274];
    Vec v280, v290;
    char pad2A0[0x2A8 - 0x2A0];
    f32 f2A8, f2AC;
    char pad2B0[0x2C0 - 0x2B0];
    Vec v2C0;
    f32 f2D0;
    s32 i2D4, i2D8;
    char pad2DC[0x2E0 - 0x2DC];
    s32 i2E0, i2E4;
    char pad2E8[0x2F0 - 0x2E8];
    Vec v2F0, v300, v310;
    f32 f320, f324;
    char pad328[0x340 - 0x328];
    Vec v340;
    f32 f350;
    char pad354[0x360 - 0x354];
    Posture() __asm__("func_00416B58");
};

/* the reference frame (func_00415350 initialises it) */
struct Frame {
    f32 pos[3];
    char pad0C[4];
    Vec v10, v20, v30, v40, v50, v60, v70, v80, v90, vA0;
    char padB0[0xE0 - 0xB0];
    f32 radius;
    char padE4[0x120 - 0xE4];
    s32 hand;
    f32 chair, f128;
    f32 &Chair() { return chair; }
    void setUp(const Vec &v) { v10 = v; }
    char pad12C[0x130 - 0x12C];
    f32 f130;
    char pad134[0x140 - 0x134];
    Frame() __asm__("func_00415350");
};

struct Input { s32 mode; char pad[12]; Vec v; Input(s32 m, const Vec &d) : mode(m), v(d) {} };
struct Seat;
struct Raw { char data[0x100]; Raw(Seat *, f32, s32) __asm__("func_00386818"); };
struct Params { void *p; char pad[12]; Params(Raw *) __asm__("func_00385470"); };
struct Defaults { char data[0x60]; Defaults() __asm__("func_003B05A8"); };
struct Crew { char pad0[4]; f32 f4; char pad8[0x58 - 8]; f32 f58, f5C; };
struct Seat { char pad[0x368]; s32 valid; char pad36C[0x370 - 0x36C]; };
struct Offset { char pad[0x34]; f32 x, y, z; };
struct Info { char pad0[2]; unsigned char type; char pad3[0x50 - 3]; Offset *offset; };
struct Self {
    char pad0[0x6A0];
    s32 f6A0;
    char pad6A4[0x6BC - 0x6A4];
    s32 busy;
    char pad6C0[0x7C0 - 0x6C0];
    s32 f7C0;
    f32 f7C4, f7C8, f7CC, f7D0, f7D4, f7D8;
};

extern "C" {
void func_00416F88(Posture *);
void func_00416FD8(Posture *, void *, Frame *, Input *, void *);
void func_00415240(Frame *, Vec *);
void func_004152B0(Frame *, s32, Vec *);
Info *func_0038DC18(CarGeometry *);
s32 func_00459178(Info *);
void *func_005A48D8(void *, s32, s32);
s32 GetPitStopStatus(void *);
f32 func_00344798(void *, f32);
f32 func_003447F8(void *, f32);
f32 func_00344828(void *, f32);
f32 func_00344858(void *, f32);
f32 func_00344888(void *, f32);
f32 func_003448B8(void *, f32);
void func_003B2508(Self *, f32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
s32 func_00402270(CarGeometry *, void *);
void func_003B1DB0(s32, void *, Params *, void *, CarGeometry *);
void func_003B1FA8(void *, CarGeometry *, f32 *, f32 *, f32 *);
void func_003B21D8(void *, CarGeometry *, f32 *, f32 *, f32 *);
void func_003B2370(CarGeometry *, f32 *, f32 *, f32 *, f32);
void func_003B2440(f32 *, f32 *, f32 *, f32);
f32 func_004860E8(void *, s32, f32);
void func_00488528(Vec *, f32, f32, f32);
void func_0048D530(Vec *, Vec *, Vec *);
void func_0057D8A0(f32 *, f32 *, f32);
Vec func_00421DF8(const Vec &, f32, f32, f32);
f32 func_00385688(Params *); f32 func_00385698(Params *); f32 func_003856A8(Params *);
f32 func_003856B8(Params *); f32 func_003856C8(Params *); f32 func_003856D8(Params *);
f32 func_003856E8(Params *); f32 func_00385700(Params *); f32 func_00385738(Params *);
f32 func_00385748(Params *); f32 func_00385758(Params *); f32 func_00385778(Params *);
f32 func_00385788(Params *); f32 func_003857A8(Params *); f32 func_003857C0(Params *);
f32 func_003857E8(Params *); f32 func_00385800(Params *); f32 func_00385828(Params *);
f32 func_00385840(Params *); f32 func_00385858(Params *); f32 func_00385868(Params *);
f32 func_00385878(Params *); f32 func_00385888(Params *); f32 func_00385898(Params *);
f32 func_003858A8(Params *); f32 func_003858B8(Params *); f32 func_003858C8(Params *);
f32 func_003858D8(Params *); f32 func_003858E8(Params *); f32 func_003858F8(Params *);
f32 func_00385908(Params *); f32 func_00385918(Params *); f32 func_00385928(Params *);
f32 func_00385938(Params *); f32 func_00385948(Params *); f32 func_00385958(Params *);
f32 func_00385968(Params *); f32 func_00385998(Params *); f32 func_003859A8(Params *);
f32 func_003859B8(Params *); f32 func_003859C8(Params *); f32 func_003859D8(Params *);
f32 func_003859E8(Params *); f32 func_003859F8(Params *); f32 func_00385A08(Params *);
f32 func_00385A18(Params *); f32 func_00385A38(Params *); f32 func_00385A48(Params *);
f32 func_00385A58(Params *); f32 func_00385A68(Params *); f32 func_00385A88(Params *);
f32 func_00385A98(Params *); f32 func_00385AA8(Params *); f32 func_00385AC0(Params *);
f32 func_00385AD0(Params *);
}
extern char D_006A2478[];

static inline f32 maxf(const f32 &a, const f32 &b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(const f32 &a, const f32 &b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 clamp(f32 v, const f32 &lo, const f32 &hi) { return minf(maxf(v, lo), hi); }

/* the car's axes to the model's: x and z flip */
struct Point {
    f32 x, y, z;
    f32 &operator[](s32 i) { return (&x)[i]; }
    Point() {}
} __attribute__((aligned(16)));
static inline void toModel(Vec &v, const f32 &x, const f32 &y, const f32 &z) { v.set(-x, y, -z); }
/* y over [x0, x1] runs linearly from y0 to y1 */
struct Linear {
    f32 a, b;
    f32 c;
    Linear(f32 x0, f32 x1, f32 y0, f32 y1) {
        f32 inv = 1.0f / (x1 - x0);
        a = inv * (y1 - y0);
        b = inv * (x1 * y0 - x0 * y1);
    }
    f32 at(f32 x) const { return a * x + b; }
};
struct Scalar { f32 v, pad; Scalar(f32 f) : v(f) {} };
static inline f32 scalar(const Scalar &s) { return s.v; }
static inline f32 offsetAngle(const Scalar &base, f32 offset) { return scalar(base) + offset; }
static inline f32 limit(f32 v, const f32 a, const f32 b) { f32 lo = a; f32 hi = b; return clamp(v, lo, hi); }
static inline f32 rangeMap(f32 x, f32 x0, f32 x1, f32 y0, f32 y1) { Linear map(x0, x1, y0, y1); f32 lo = y0, hi = y1; if (y1 < y0) { lo = y1; hi = y0; } return minf(maxf(map.at(x), lo), hi); }
/* kind 5 seats crouch: the flag value comes through a const ref, so the select is formed after combine */
static inline void setCrouch(Posture &p, s32 kind, const s32 &on) { if (kind == 5) p.i2E0 = on; }
static inline void readPoint(Params *p, Point &d) { d[0] = func_00385878(p); d[1] = func_00385888(p); d[2] = func_00385898(p); }
static inline f32 maxOf(const f32 &a, const f32 &b) { return a < b ? b : a; }
static inline void setUnit(f32 &dst, f32 v) { dst = clamp(v, 0.0f, 1.0f); }
static inline void limitAngle(Posture &p, f32 a) { if (!p.i2D8) { p.f268 = minf(maxf(a, p.f270), p.f26C); return; } p.f268 = a; }
static inline void copy3(f32 *d, const Vec &v) { d[0] = v.f.x; d[1] = v.f.y; d[2] = v.f.z; }
static inline void solve(Posture &p, void *body, Frame &f, Input *in) { func_00416FD8(&p, body, &f, in, 0); }
static inline f32 clampAbs(f32 v, f32 k) { f32 lo = -k; f32 hi = k; return clamp(v, lo, hi); }
static inline Vec rotate(const Vec &a, const Vec &b) { Vec r; func_0048D530(&r, (Vec *)&a, (Vec *)&b); return r; }

extern "C" s32 func_003B2708(Self *self, CarGeometry *geo, void *car, s32 driver, Crew *crew,
                             s32 force, s32 copilot, f32 t) {

    self->busy = 1;
    Posture posture;
    char *seats = (char *)car + 0x9A0;
    Frame frame;
    s32 index = driver == 0;
    Seat *seat = &((Seat *)seats)[index];
    if (seat->valid == 0 || func_0038DC18(geo) == 0) {
        self->busy = 0;
        return 0;
    }
    s32 rally = 0;
    if (func_0038DC18(geo)->type == 0x11) rally = copilot != 0;
    Offset *offset = func_0038DC18(geo)->offset;
    f32 shift[3];
    func_005A48D8(shift, 0, sizeof(shift));
    if (offset) {
        shift[0] = offset->x;
        shift[1] = offset->y;
        shift[2] = offset->z;
    }
    s32 view = 3;
    s32 look = 0;
    unsigned char type = func_0038DC18(geo)->type;
    if (type == 5 && copilot) {
        view = 2;
    } else if (type == 0x11) {
        if ((unsigned)(GetPitStopStatus(car) - 2) < 4) view = 0;
    }
    if (force) {
        look = 2;
        view = 3;
    }
    f32 a = func_00344798(car, t);
    char *body = (char *)self + 0x10;
    f32 b = func_003447F8(car, t);
    f32 c = func_00344828(car, t);
    f32 d = func_00344858(car, t);
    f32 e = func_003448B8(car, t);
    func_003B2508(self, a, b, c, d, e, -func_00344888(car, t), shift[0], shift[1], shift[2], rally, view, look);
    s32 state = *(s32 *)(body + 0x690);
    if (copilot && state == 3) return 0;
    if (self->f7C0 > 0) return 0;
    s32 drawPosture = 1;
    s32 drawHands = 1;
    s32 mode = func_00459178(func_0038DC18(geo));
    s32 result = 1;
    if (copilot) {
        switch (mode) {
        case 0:
            self->busy = 0;
            return 0;
        case 1:
            drawPosture = 0;
            posture.iC8 = result;
            posture.iBC = 0;
            drawHands = 0;
            posture.iC0 = 0;
            break;
        case 2:
            posture.iC0 = 0;
            posture.iC8 = result;
            if ((rally > 0 && state > 0) || state >= 3) {
                posture.iBC = 0;
                result = 0;
            } else {
                posture.iCC = result;
            }
            drawHands = 0;
            drawPosture = 1;
            break;
        case 3:
            drawPosture = 1;
            drawHands = 1;
            break;
        }
    }

    f32 seatY = 0.0f;
    Raw raw(seat, t, 1);
    s32 near = 0;
    s32 other = 1;
    Params params(&raw);
    f32 lift = 0.0f;
    f32 reach = 0.0f;
    Defaults defaults;
    f32 seatZ = 0.0f;
    s32 kind = func_00402270(geo, seats + 0x6E0);
    if (!driver) posture.i2D4 = other;
    if (kind == other) {
        func_00416F88(&posture);
        seatY += func_003856D8(&params) * 0x1.999998p-7f;
        f32 lean = func_003856D8(&params);
        /* lean range: pi/10 (18 degrees), never negative (inferred). The compare of the two literals
         * (bound to const refs) is only resolved after cse2, so range is not folded into the map below. */
        f32 range = maxOf(0x1.41b2f4p-2f, 0.0f);
        Linear map(-range, range, 0x1.999998p-4f, -0x1.999998p-4f);
        f32 lo = -0x1.999998p-4f, hi = 0x1.999998p-4f;
        f32 leaned = lean * -0x1.999998p-5f + seatZ;
        seatZ = leaned;
        seatZ += minf(maxf(map.at(func_003856B8(&params)), lo), hi);
    }
    if (kind == 3) {
        posture.i2E4 = other;
        f32 extended = func_00385968(&params) + reach;
        reach = extended;
        posture.f26C = 0x1.921fb4p+0f;
    }
    if (kind == 4) {
        posture.i2E4 = 2;
        reach += func_00385968(&params);
    }
    if (crew == 0) crew = (Crew *)&defaults;
    func_003B1DB0(kind, crew, &params, car, geo);
    if (func_003856C8(&params) > 0x1.47ae14p-7f) {
        lift = 0x1.47ae14p-7f;
        seatY += func_003856C8(&params) - lift;
    } else {
        f32 raised = func_003856C8(&params) + lift;
        lift = raised;
    }
    s32 lying = 3;
    Vec p;
    {
        Vec v;
        p.set(0.0f, lift, 0.0f);
        posture.v2C0 = p;
        p.set(geo->GetStepPosition_X(0, t), geo->GetStepPosition_Y(0, t), geo->GetStepPosition_Z(0, t));
        toModel(v, p.f.x, p.f.y, p.f.z);
        frame.v20 = v;
        p.set(geo->GetStepPosition_X(1, t), geo->GetStepPosition_Y(1, t), geo->GetStepPosition_Z(1, t));
        toModel(v, p.f.x, p.f.y, p.f.z);
        frame.v30 = v;
        p.set(geo->GetSeatPosition_X(t), geo->GetSeatPosition_Y(t) + seatY, geo->GetSeatPosition_Z(t) + seatZ);
        toModel(v, p.f.x, p.f.y, p.f.z);
        frame.v40 = v;
        p.set(geo->GetSteeringWheelCenter_X(t), geo->GetSteeringWheelCenter_Y(t), geo->GetSteeringWheelCenter_Z(t));
        toModel(v, p.f.x, p.f.y, p.f.z);
        frame.v50 = v;
        {
            p.set(geo->GetSteeringWheelNormal_X(t), geo->GetSteeringWheelNormal_Y(t), geo->GetSteeringWheelNormal_Z(t));
            toModel(v, p.f.x, p.f.y, p.f.z);
            Vec &normal = v;
            func_00415240(&frame, &normal);
        }
        p.set(geo->GetShiftPosition_X(t), geo->GetShiftPosition_Y(t), geo->GetShiftPosition_Z(t));
        toModel(v, p.f.x, p.f.y, p.f.z);
        frame.v60 = v;
        p.set(geo->GetSideBrakePosition_X(t), geo->GetSideBrakePosition_Y(t), geo->GetSideBrakePosition_Z(t));
        toModel(v, p.f.x, p.f.y, p.f.z);
        frame.v70 = v;
        if (kind == lying) {
            p.set(0x1.06a7eep-1f, 0x1.05a1cap+0f, -0x1.ae147ap-4f);
            toModel(v, p.f.x, p.f.y, p.f.z);
            frame.v80 = v;
        }
        else {
            p.set(geo->GetSideBrakePosition_X(t), geo->GetSideBrakePosition_Y(t), geo->GetSideBrakePosition_Z(t));
            toModel(v, p.f.x, p.f.y, p.f.z);
            frame.v80 = v;
        }
        frame.radius = geo->GetSteeringWheelRadius();
        if (geo->IsFixedHandle()) {
            p.set(geo->GetFixedLeftHandlePosition_X(t), geo->GetFixedLeftHandlePosition_Y(t), geo->GetFixedLeftHandlePosition_Z(t));
            toModel(v, p.f.x, p.f.y, p.f.z);
            frame.v90 = v;
            p.set(geo->GetFixedRightHandlePosition_X(t), geo->GetFixedRightHandlePosition_Y(t), geo->GetFixedRightHandlePosition_Z(t));
            toModel(v, p.f.x, p.f.y, p.f.z);
            frame.vA0 = v;
            {
                p.set(geo->GetFixedLeftHandleVector_X(t), geo->GetFixedLeftHandleVector_Y(t), geo->GetFixedLeftHandleVector_Z(t));
                toModel(v, p.f.x, p.f.y, p.f.z);
                Vec &left = v;
                func_004152B0(&frame, 0, &left);
            }
            {
                p.set(geo->GetFixedRightHandleVector_X(t), geo->GetFixedRightHandleVector_Y(t), geo->GetFixedRightHandleVector_Z(t));
                toModel(v, p.f.x, p.f.y, p.f.z);
                Vec &right = v;
                func_004152B0(&frame, 1, &right);
            }
            frame.hand = 0;
        } else if (geo->GetSteeringWheelCenter_X(t) < geo->GetShiftPosition_X(t)) {
            frame.hand = 2;
            posture.f250[1] = func_003859D8(&params);
            posture.f258[1] = func_00385A48(&params);
            posture.f260[1] = func_00385A98(&params);
            near = 1;
        } else {
            frame.hand = 1;
            posture.f250[0] = func_003859C8(&params);
            posture.f258[0] = func_00385A38(&params);
            posture.f260[0] = func_00385A88(&params);
            near = 0;
        }
    }
    other = near == 0;
    frame.f128 = 0x1.921fb4p+0f;
    frame.Chair() = geo->GetChairAngle(t);
    {
        const Scalar &ax = Scalar(self->f7D0);
        const Scalar &ay = Scalar(self->f7D4);
        const Scalar &az = Scalar(self->f7D8);
        func_00488528(&p, scalar(ax), scalar(ay), scalar(az));
    }
    frame.pos[0] = self->f7C4;
    frame.pos[1] = self->f7C8;
    frame.pos[2] = self->f7CC;
    frame.setUp(rotate(p, Vec(0.0f, 1.0f, 0.0f, 0.0f)));
    f32 brake = 1.0f;
    frame.f130 = func_00385AA8(&params);
    posture.f350 = func_00385AA8(&params);
    posture.f21C = crew->f4;
    posture.f220 = func_003857A8(&params);
    posture.f224 = func_003857C0(&params);
    posture.f228 = func_003857E8(&params);
    posture.f22C = func_00385800(&params);
    posture.f230 = clamp(func_00385828(&params), 0.0f, 1.0f);
    posture.f234 = clamp(func_00385840(&params), 0.0f, 1.0f);
    if (kind == 5) {
        posture.f238 = func_003858D8(&params) * func_00385A58(&params);
        posture.f23C = func_003858E8(&params) * func_00385A58(&params);
        posture.f240 = func_003858F8(&params) * func_00385A58(&params);
        posture.f244 = func_00385908(&params) * func_00385A58(&params);
    } else {
        posture.f238 = func_003858D8(&params);
        posture.f23C = func_003858E8(&params);
        posture.f240 = func_003858F8(&params);
        posture.f244 = func_00385908(&params);
    }
    posture.f248 = func_003859A8(&params);
    f32 &unit = posture.f08;
    posture.f24C = func_003859B8(&params);
    setUnit(unit, func_00385AC0(&params));
    f32 stiff = func_00385AD0(&params);
    setCrouch(posture, kind, 1);
    posture.f0C = clamp(stiff, 0.0f, 1.0f);
    f32 roll = func_003856A8(&params);
    if (kind != 1) {
        f32 offset = reach + func_003856B8(&params);
        f32 angle = offsetAngle(frame.Chair(), offset);
        limitAngle(posture, angle);
        posture.i200 = 1;
        posture.f5C = clampAbs(roll, 0x1.921fb4p-1f);
        posture.f50 = clampAbs(roll * 0x1.999998p-3f + func_00385938(&params), 0x1.e28c6ep-1f);
    } else {
        f32 offset = func_003856B8(&params) * 0x1.999998p-4f;
        f32 angle = offsetAngle(frame.Chair(), offset);
        limitAngle(posture, angle);
        posture.i200 = 1;
        posture.f5C = clampAbs(roll, 0x1.921fb4p-1f);
        posture.f50 = clampAbs((roll * 0x1.999998p-3f + func_00385938(&params)) * 0x1.999998p-4f, 0x1.e28c6ep-1f);
    }
    f32 blend = 0.0f;
    posture.f54 = clampAbs(func_00385998(&params), 0x1.41b2f4p-2f);
    posture.f2D0 = func_003859E8(&params);
    posture.f74 = func_003859F8(&params);
    f32 w0 = func_00385700(&params);
    f32 w1 = func_00385A08(&params);
    f32 w2 = func_00385A58(&params);
    f32 phase = func_00385AA8(&params);
    if (phase <= 1.0f) {
        blend = (1.0f - phase) * w0 + phase * w1;
    } else if (phase <= 2.0f) {
        phase -= 1.0f;
        blend = (1.0f - phase) * w1 + phase * w2;
    } else if (phase <= 3.0f) {
        phase -= 2.0f;
        blend = (1.0f - phase) * w2 + phase * w0;
    }
    Vec hip(0.0f, 0.0f, 0.0f);
    Vec head(0.0f, 0.0f, 0.0f);
    Vec eye(0.0f, 0.0f, 0.0f);
    f32 gripNear, gripOther;
    if (driver && geo->IsFixedHandle() != 1) {
        gripNear = near == 0 ? func_00385778(&params) : func_00385788(&params);
        gripOther = other == 0 ? func_00385778(&params) : func_00385788(&params);
        if (drawPosture) {
            f32 hx, hy, hz;
            if (kind == 5) func_003B1FA8(crew, geo, &hx, &hy, &hz);
            else func_003B21D8(crew, geo, &hx, &hy, &hz);
            f32 *h = &hip.f.x;
            h[0] = hx;
            h[1] = hy;
            h[2] = hz;
            if (kind == 3) {
                func_003B2370(geo, &head.f.x, &head.f.y, &head.f.z, func_00385A18(&params));
                func_003B2440(&eye.f.x, &eye.f.y, &eye.f.z, func_00385A68(&params));
            }
            if (blend < 0.5f) {
                f32 k = 2.0f * blend;
                gripNear = rangeMap(blend, 0.0f, 0.5f, 0x1.333332p-2f, 0.75f) * k + gripNear * (1.0f - k);
            } else {
                f32 k = 2.0f * (1.0f - blend);
                gripNear = rangeMap(blend, 0.5f, 1.0f, 0.75f, 0x1.333332p-2f) * k + gripNear * (1.0f - k);
            }
        }
    } else {
        gripOther = 0x1.999998p-3f;
        gripNear = 0x1.999998p-3f;
    }
    posture.f210 = clamp(w0, 0.0f, 1.0f);
    posture.f214 = clamp(w1, 0.0f, 1.0f);
    posture.f218 = clamp(w2, 0.0f, 1.0f);
    posture.v2F0 = hip;
    posture.v300 = head;
    posture.v310 = eye;
    Posture &pose = posture;
    f32 reachA = func_00385738(&params);
    f32 reachB = func_00385748(&params);
    posture.f320 = reachA;
    posture.f324 = reachB;
    pose.grip[near] = clamp(gripNear, 0.0f, 1.0f);
    pose.grip[other] = clamp(gripOther, 0.0f, 1.0f);
    Point look3;
    readPoint(&params, look3);
    Input input(1, Vec(look3[0], look3[1], look3[2]));
    Vec lean(0.0f, 0.0f, 0.0f);
    Vec pedal(0.0f, 0.0f, 0.0f);
    if (drawHands) {
        if (kind == 1) {
            brake = 0.25f;
            pedal.f.y = crew->f58 * 0x1.f3b644p-5f;
            lean.f.y = crew->f5C * 0x1.f3b644p-5f;
            pedal.f.z = crew->f58 * -0x1.de353ep-2f;
            lean.f.z = crew->f5C * -0x1.de353ep-2f;
            f32 t = func_004860E8(D_006A2478, 10, func_003856D8(&params)) * 0x1.999998p-4f;
            Vec tilt(0.0f, t, 0.0f);
            posture.v340 = tilt;
        } else {
            if ((unsigned)(kind - 3) >= 2 && geo->IsFixedFoot() != 1) {
                f32 m = maxf(func_003856D8(&params), func_003856E8(&params));
                f32 p = func_00385758(&params);
                lean.f.y = m * -0x1.47ae14p-4f;
                pedal.f.y = p * -0x1.47ae14p-4f;
            }
        }
    }
    posture.v290 = lean;
    posture.v280 = pedal;
    posture.f2A8 = func_00385858(&params);
    posture.f2AC = func_00385868(&params);
    posture.f68 = limit(func_003858A8(&params) * brake, 0.0f, 1.0f);
    f32 h0 = func_00385698(&params);
    f32 h1 = func_003858C8(&params);
    posture.f64 = (h0 - h1) + func_003858B8(&params) * 0x1.999998p-4f + 0x1.657182p-4f;
    f32 h2 = func_00385688(&params);
    posture.f6C = h2 + func_003858B8(&params) * 0.25f;
    f32 sn, cs;
    func_0057D8A0(&sn, &cs, -func_003858B8(&params));
    Vec fwd = func_00421DF8(p, 0.0f, cs, sn);
    copy3(posture.v90, fwd);
    if (kind == 1) solve(posture, body, frame, 0);
    else solve(posture, body, frame, &input);
    *(f32 *)((char *)self + 0x690) = func_00385918(&params);
    *(f32 *)((char *)self + 0x694) = func_00385928(&params);
    *(f32 *)(body + 0x688) = func_00385948(&params);
    *(f32 *)(body + 0x68C) = func_00385958(&params);
    return result;
}
