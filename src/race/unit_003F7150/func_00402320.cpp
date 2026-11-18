/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Driver posture reset (race unit 0x3F7150). The posture blocks are reached through out-of-line
 * accessors (func_00385AE0.. on the pose handle, func_003861C0.. on the frame handle,
 * func_00385F70.. on the state handle) that return a pointer to one field each. Vec, Quat, Angle
 * and Scalar are the race code's small value types, written as in func_0041D140 and
 * func_0040D0A0; their inline members (put, the X()/Y()/Z() references, normal(), up()) are what
 * fix retail's register and stack-slot choices. */
typedef int s32;
typedef float f32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Data { char pad[0x10]; f32 nx, ny; char pad18[0x40]; f32 px, py, pz; char pad64[6]; unsigned short type; };
struct Vec {
    union { u128 q; struct { f32 x, y, z, w; }; };
    Vec() {}
    void put(f32 a, f32 b, f32 c) { x = a; y = b; z = c; }
    void up(const Data *d);
    f32 &X() { return x; }
    f32 &Y() { return y; }
    f32 &Z() { return z; }
    Vec(const Vec &v) { q = v.q; }
    Vec &operator=(const Vec &v) { q = v.q; return *this; }
    void normalize() {
        f32 s = 1.0f, d = x * x + y * y + z * z;
        __asm__("rsqrt.s %0, %1, %2" : "=f"(s) : "f"(s), "f"(d));
        x *= s;
        y *= s;
        z *= s;
    }
    Vec normal() const { Vec r; r.q = q; r.normalize(); return r; }
} __attribute__((aligned(16)));
struct Quat {
    union { u128 q; struct { f32 x, y, z, w; }; };
    Quat() {}
    Quat(const Quat &v) { q = v.q; }
    Quat &operator=(const Quat &v) { q = v.q; return *this; }
} __attribute__((aligned(16)));
struct Angle {
    f32 a;
    Angle() {}
    Angle(const Angle &o) : a(o.a) {}
    f32 value() const { return a; }
};

/* the posture handles (each holds a pointer to its block) and their field accessors */
/* the shift lever description of the car (func_00386660 is its constructor) */
struct Shifter { s32 a; const s32 b; Shifter(s32 v) __asm__("func_00386660"); s32 get() const { return a; } };
struct Info { char pad[0x50]; Data *data; };
struct Local { char pad[0x20]; Local(void *car, s32 index) __asm__("func_0038DB30"); };
extern "C" {
void func_00385470(s32 *, s32);
void func_00385EC8(s32 *, s32);
void func_00386148(s32 *, s32);
Info *func_0038DC18(Local *);
s32 func_00402270(Local *, s32);
s32 func_00386610(Shifter *);
s32 func_00386620(Shifter *);
s32 func_00386630(Shifter *);
s32 func_00386640(Shifter *);
void func_00411EB0(s32, s32, s32, s32, s32, f32 *, f32 *) throw();
void func_0040DC08(Local *, f32 *, f32 *, f32 *, f32, f32);
Angle func_00423450(const Vec *, const Vec *);
void func_00488528(Quat *, f32, f32, f32);
Vec Numerical_Math__Quaternion__rotate(const Quat *, const Vec *);
f32 func_00344798(void *, f32);
f32 func_003447F8(void *, f32);
f32 func_00344828(void *, f32);
f32 func_00344858(void *, f32);
f32 func_00344888(void *, f32);
f32 func_003448B8(void *, f32);
f32 CarGeometry__GetSeatPosition_X(Local *, f32);
f32 CarGeometry__GetSeatPosition_Y(Local *, f32);
f32 CarGeometry__GetSeatPosition_Z(Local *, f32);
f32 CarGeometry__GetSteeringWheelCenter_X(Local *, f32);
f32 CarGeometry__GetSteeringWheelCenter_Y(Local *, f32);
f32 CarGeometry__GetSteeringWheelCenter_Z(Local *, f32);
f32 CarGeometry__GetSteeringWheelNormal_X(Local *, f32);
f32 CarGeometry__GetSteeringWheelNormal_Y(Local *, f32);
f32 CarGeometry__GetSteeringWheelNormal_Z(Local *, f32);
f32 CarGeometry__GetSteeringWheelRadius(Local *);
f32 CarGeometry__GetShiftPosition_X(Local *, f32);
f32 CarGeometry__GetShiftPosition_Y(Local *, f32);
f32 CarGeometry__GetShiftPosition_Z(Local *, f32);
f32 CarGeometry__GetShiftLength(Local *, f32);
void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter(void);
f32 func_0044FA20(void *);
s32 func_00386480(s32 *);
f32 *func_00386468(s32 *, s32);
void func_00385FD0(s32 *, s32);
void func_00385FE0(s32 *, s32);
void func_00385FF0(s32 *, s32);
void func_00386000(s32 *, s32);
void func_00386010(s32 *, s32);
void func_00386020(s32 *, s32);
void func_00386030(s32 *, s32, s32);
void func_003860B0(s32 *, s32, s32);
s32 *func_00385F70(s32 *); s32 *func_00385F80(s32 *); s32 *func_00385F90(s32 *); s32 *func_00385FA0(s32 *);
s32 *func_00385FB0(s32 *); s32 *func_00385FC0(s32 *); s32 *func_00386138(s32 *);
s32 *func_00385C38(s32 *); s32 *func_00385C48(s32 *);
s32 *func_00385D18(s32 *); s32 *func_00385D28(s32 *); s32 *func_00385C98(s32 *); s32 *func_00385DB8(s32 *);
s32 *func_00385DD8(s32 *); s32 *func_00385DE8(s32 *); s32 *func_00385DF8(s32 *); s32 *func_00385E18(s32 *);
s32 *func_00385E28(s32 *); s32 *func_00385E38(s32 *); s32 *func_00385D78(s32 *);
f32 *func_00385AE0(s32 *);
f32 *func_00385AE8(s32 *);
f32 *func_00385AF8(s32 *);
f32 *func_00385B08(s32 *);
f32 *func_00385B18(s32 *);
f32 *func_00385B28(s32 *);
f32 *func_00385B38(s32 *);
f32 *func_00385B48(s32 *);
f32 *func_00385B58(s32 *);
f32 *func_00385B68(s32 *);
f32 *func_00385B78(s32 *);
f32 *func_00385B88(s32 *);
f32 *func_00385B98(s32 *);
f32 *func_00385BA8(s32 *);
f32 *func_00385BB8(s32 *);
f32 *func_00385BC8(s32 *);
f32 *func_00385BD8(s32 *);
f32 *func_00385BE8(s32 *);
f32 *func_00385BF8(s32 *);
f32 *func_00385C08(s32 *);
f32 *func_00385C18(s32 *);
f32 *func_00385C28(s32 *);
f32 *func_00385C58(s32 *);
f32 *func_00385C68(s32 *);
f32 *func_00385C78(s32 *);
f32 *func_00385C88(s32 *);
f32 *func_00385CA8(s32 *);
f32 *func_00385CB8(s32 *);
f32 *func_00385CC8(s32 *);
f32 *func_00385CD8(s32 *);
f32 *func_00385CE8(s32 *);
f32 *func_00385CF8(s32 *);
f32 *func_00385D08(s32 *);
f32 *func_00385D38(s32 *);
f32 *func_00385D88(s32 *);
f32 *func_00385D98(s32 *);
f32 *func_00385DA8(s32 *);
f32 *func_00385DC8(s32 *);
f32 *func_00385E08(s32 *);
f32 *func_00385E48(s32 *);
f32 *func_00385E58(s32 *);
f32 *func_00385E68(s32 *);
f32 *func_00385E78(s32 *);
f32 *func_003861C0(s32 *);
f32 *func_003861C8(s32 *);
f32 *func_003861D8(s32 *);
f32 *func_003861E8(s32 *);
f32 *func_003861F8(s32 *);
f32 *func_00386208(s32 *);
f32 *func_00386218(s32 *);
f32 *func_00386228(s32 *);
f32 *func_00386238(s32 *);
f32 *func_00386248(s32 *);
f32 *func_00386258(s32 *);
f32 *func_00386268(s32 *);
f32 *func_00386278(s32 *);
f32 *func_00386288(s32 *);
f32 *func_00386298(s32 *);
f32 *func_003862A8(s32 *);
f32 *func_003862B8(s32 *);
f32 *func_003862C8(s32 *);
f32 *func_003862D8(s32 *);
f32 *func_003862E8(s32 *);
f32 *func_003862F8(s32 *);
f32 *func_00386308(s32 *);
f32 *func_00386318(s32 *);
f32 *func_00386328(s32 *);
f32 *func_00386338(s32 *);
f32 *func_00386348(s32 *);
f32 *func_00386358(s32 *);
f32 *func_00386368(s32 *);
f32 *func_00386378(s32 *);
f32 *func_00386388(s32 *);
f32 *func_00386398(s32 *);
f32 *func_003863A8(s32 *);
f32 *func_003863B8(s32 *);
f32 *func_003863C8(s32 *);
f32 *func_003863D8(s32 *);
f32 *func_003863E8(s32 *);
f32 *func_003863F8(s32 *);
f32 *func_00386408(s32 *);
f32 *func_00386418(s32 *);
f32 *func_00386428(s32 *);
f32 *func_00386438(s32 *);
f32 *func_00386448(s32 *);
f32 *func_00386458(s32 *);
f32 *func_00386488(s32 *);
f32 *func_00386498(s32 *);
f32 *func_003864A8(s32 *);
f32 *func_003864B8(s32 *);
f32 *func_003864C8(s32 *);
f32 *func_003864D8(s32 *);
f32 *func_003864E8(s32 *);
f32 *func_003864F8(s32 *);
f32 *func_00386508(s32 *);
f32 *func_00386518(s32 *);
f32 *func_00386528(s32 *);
f32 *func_00386538(s32 *);
f32 *func_00386548(s32 *);
f32 *func_00386558(s32 *);
f32 *func_00386568(s32 *);
f32 *func_00386578(s32 *);
f32 *func_00386588(s32 *);
f32 *func_00386598(s32 *);
}
extern Vec D_00622B10;
inline void Vec::up(const Data *d) {
    if (d->nx == 0.0f) {
        *this = D_00622B10;
    } else {
        X() = 0.0f;
        Y() = d->ny;
        Z() = -d->nx;
        *this = normal();
    }
}
struct Scalar { f32 v; Scalar(f32 f) : v(f) {} } __attribute__((aligned(16)));
static inline f32 scalar(const Scalar &s) { return s.v; }

/* Driver posture reset (inferred): binds the posture blocks of self to the car, clears every
 * posture value, then sets the arm and head limits by the driver type func_00402270 returns,
 * the hand rest positions, the seat frame and the timing parameters. */
extern "C" void func_00402320(char *self, char *car, s32 index) {
    s32 pose;
    s32 state;
    s32 frame;
    *(s32 *)(self + 0x364) = index;
    func_00385470(&pose, (s32)(self + 0x160));
    func_00385EC8(&state, (s32)self);
    func_00386148(&frame, (s32)(self + 0x40));
    Shifter shift((s32)(car + 0x1080));
    Local local(car, *(s32 *)(self + 0x360));
    Vec pos, dir;
    if (!func_0038DC18(&local)) {
        *(s32 *)(self + 0x368) = 0;
        return;
    }
    *(s32 *)(self + 0x368) = 1;
    Data *info = func_0038DC18(&local)->data;
    s32 seat = *(unsigned char *)(car + 0x544);
    s32 gear = *(unsigned char *)(car + 0x624);
    s32 kind = func_00402270(&local, shift.get());
    *func_00385AE0(&pose) = 0.0f;
    *func_003861C0(&frame) = 0.0f;
    *func_00385AE8(&pose) = 0.0f;
    *func_003861C8(&frame) = 0.0f;
    *func_00385AF8(&pose) = 0.0f;
    *func_003861D8(&frame) = 0.0f;
    *func_00385B08(&pose) = 0.0f;
    *func_003861E8(&frame) = 0.0f;
    *func_00385B18(&pose) = 0.0f;
    *func_003861F8(&frame) = 0.0f;
    *func_00385B28(&pose) = 0.0f;
    *func_00386208(&frame) = 0.0f;
    *func_00385B38(&pose) = 0.0f;
    *func_00386218(&frame) = 0.0f;
    *func_00385B48(&pose) = 0.0f;
    *func_00386228(&frame) = 0.0f;
    *func_00385B78(&pose) = 0.0f;
    *func_00385B88(&pose) = 0.0f;
    *func_00386258(&frame) = 0.0f;
    *func_00386268(&frame) = 0.0f;
    *func_00385B98(&pose) = 0.0f;
    func_00411EB0(func_00386610(&shift), func_00386620(&shift), func_00386630(&shift), func_00386640(&shift),
                  gear, func_00385B58(&pose), func_00385B68(&pose));
    *func_00386238(&frame) = 0.0f;
    *func_00386248(&frame) = 0.0f;
    func_0040DC08(&local, func_00385C58(&pose), func_00385C68(&pose), func_00385C78(&pose), 0.0f, 0.0f);
    *func_00386278(&frame) = 0.0f;
    *func_00386288(&frame) = 0.0f;
    *func_00386298(&frame) = 0.0f;
    *func_00385BA8(&pose) = 0.0f;
    *func_00385BB8(&pose) = 0x1.333332p-2f;
    *func_00385BC8(&pose) = 0x1.333332p-2f;
    if (info->type == 1) {
        *func_00385BD8(&pose) = -0x1.921fb4p+0f;
        *func_00385BE8(&pose) = 0x1.921fb4p+0f;
        *func_00385DA8(&pose) = 0.0f;
        *func_00385D88(&pose) = 0.0f;
        *func_00385D98(&pose) = 0.0f;
        *func_00385E08(&pose) = 0.0f;
        *func_00385E48(&pose) = 0.0f;
    } else if (kind == 3) {
        *func_00385BD8(&pose) = -0x1.2d97c6p+1f;
        *func_00385BE8(&pose) = 0x1.2d97c6p+1f;
        *func_00385DA8(&pose) = -0x1.197c96p+0f;
        *func_00385D88(&pose) = 0.0f;
        *func_00385D98(&pose) = 0.0f;
        *func_00385E08(&pose) = -0x1.921fb4p+0f;
        *func_00385E48(&pose) = -0x1.921fb4p+0f;
    } else if (kind == 4) {
        *func_00385BD8(&pose) = -0x1.921fb4p+1f;
        *func_00385BE8(&pose) = 0x1.921fb4p+1f;
        *func_00385DA8(&pose) = -0x1.921fb4p+0f;
        *func_00385D88(&pose) = 0.0f;
        *func_00385D98(&pose) = 0.0f;
        *func_00385E08(&pose) = 0.0f;
        *func_00385E48(&pose) = 0.0f;
    } else if (kind == 5) {
        pos.put(info->px, info->py, info->pz);
        dir.up(info);
        *func_00385BD8(&pose) = -0x1.197c96p+0f;
        *func_00385BE8(&pose) = func_00423450(&dir, &pos).value();
        *func_00385DA8(&pose) = 0.0f;
        *func_00385D88(&pose) = 0.0f;
        *func_00385D98(&pose) = 0.0f;
        *func_00385E08(&pose) = 0.0f;
        *func_00385E48(&pose) = 0.0f;
    } else {
        *func_00385BD8(&pose) = -0x1.197c96p+0f;
        *func_00385BE8(&pose) = 0x1.197c96p+0f;
        *func_00385DA8(&pose) = -0x1.becde2p-1f;
        *func_00385D88(&pose) = 0.0f;
        *func_00385D98(&pose) = 0.0f;
        *func_00385E08(&pose) = 0.0f;
        *func_00385E48(&pose) = 0.0f;
    }
    *func_003863F8(&frame) = *func_00385BD8(&pose);
    *func_00386408(&frame) = *func_00385BE8(&pose);
    *func_00385BF8(&pose) = *func_00385BD8(&pose);
    *func_00385C08(&pose) = *func_00385BE8(&pose);
    *func_00385C18(&pose) = 1.0f;
    *func_00385C28(&pose) = 1.0f;
    *func_00385C38(&pose) = 0;
    *func_00385C48(&pose) = 0;
    *func_00385F70(&state) = 0;
    *func_00385F80(&state) = 0;
    *func_00385F90(&state) = -1;
    *func_00385FA0(&state) = (u64)(u32)(seat * 0x83 + *(s32 *)(self + 0x360) * 0x1FE1 + 0x653) * 0x0900D309 + 1;
    *func_00385FB0(&state) = 1;
    *func_00385FC0(&state) = 0;
    func_00385FD0(&state, gear);
    func_00385FE0(&state, gear);
    func_00385FF0(&state, 0);
    func_00386000(&state, 0);
    func_00386010(&state, 0);
    func_00386020(&state, 0);
    func_00386030(&state, 0, 0);
    func_00386030(&state, 1, 0);
    func_003860B0(&state, 0, 0);
    func_003860B0(&state, 1, 0);
    *func_00386138(&state) = 0;
    f32 *eye = (f32 *)(car + 0x648);
    pos.X() = eye[0];
    pos.Y() = eye[2];
    pos.Z() = -eye[1];
    *func_003862D8(&frame) = pos.x;
    *func_003862E8(&frame) = pos.y;
    *func_003862F8(&frame) = pos.z;
    *func_00386308(&frame) = 0.0f;
    *func_00386318(&frame) = 0.0f;
    *func_00386328(&frame) = 0.0f;
    *func_00386348(&frame) = 0.0f;
    f32 *tp = func_00386358(&frame);
    *tp = 0.0f;
    f32 t = *tp;
    Quat q;
    {
        const Scalar &ax = Scalar(func_00344858(car, t));
        const Scalar &ay = Scalar(func_003448B8(car, t));
        const Scalar &az = Scalar(-func_00344888(car, t));
        func_00488528(&q, scalar(ax), scalar(ay), scalar(az));
    }
    dir.X() = CarGeometry__GetSeatPosition_X(&local, t);
    dir.Y() = CarGeometry__GetSeatPosition_Y(&local, t);
    dir.Z() = CarGeometry__GetSeatPosition_Z(&local, t);
    dir = Numerical_Math__Quaternion__rotate(&q, &dir);
    *func_003862A8(&frame) = func_00344798(car, t) + dir.X();
    *func_003862B8(&frame) = func_003447F8(car, t) + dir.y;
    *func_003862C8(&frame) = func_00344828(car, t) + dir.z;
    *func_00386338(&frame) = *func_003862B8(&frame);
    *func_00386368(&frame) = t;
    *func_00386378(&frame) = t;
    *func_00386388(&frame) = t;
    *func_00386398(&frame) = t;
    *func_003863A8(&frame) = *func_00385C58(&pose);
    *func_003863B8(&frame) = *func_00385C68(&pose);
    *func_003863C8(&frame) = *func_00385C78(&pose);
    *func_00386418(&frame) = t;
    *func_00386428(&frame) = t;
    *func_003863D8(&frame) = *func_00385BD8(&pose);
    *func_003863E8(&frame) = *func_00385BE8(&pose);
    *func_00386438(&frame) = t;
    *func_00386448(&frame) = t;
    *func_00386458(&frame) = 1.0f;
    for (s32 i = 0; i < func_00386480(&frame); i++)
        *func_00386468(&frame, i) = 0.0f;
    *func_00385C88(&pose) = 0.5f;
    if (kind != 5) {
        *func_00385CB8(&pose) = 0.0f;
        *func_00385CC8(&pose) = 0.0f;
        *func_00385CD8(&pose) = 0.0f;
        *func_00385CE8(&pose) = 0.0f;
    } else {
        f32 ka = CarGeometry__GetSteeringWheelNormal_X(&local, 0.0f);
        f32 kb = CarGeometry__GetSteeringWheelNormal_Y(&local, 0.0f);
        f32 kc = CarGeometry__GetSteeringWheelNormal_Z(&local, 0.0f);
        f32 back = -ka * CarGeometry__GetSteeringWheelCenter_X(&local, 0.0f) - kb * CarGeometry__GetSteeringWheelCenter_Y(&local, 0.0f) - kc * CarGeometry__GetSteeringWheelCenter_Z(&local, 0.0f);
        f32 reach = ka * CarGeometry__GetShiftPosition_X(&local, 0.0f) + kb * CarGeometry__GetShiftPosition_Y(&local, 0.0f) + kc * CarGeometry__GetShiftPosition_Z(&local, 0.0f) + back;
        *func_00385CB8(&pose) = 0.0f;
        *func_00385CC8(&pose) = CarGeometry__GetShiftLength(&local, 0.0f) - CarGeometry__GetSteeringWheelRadius(&local);
        *func_00385CD8(&pose) = 0.0f;
        *func_00385CE8(&pose) = reach - 0.04f;
    }
    *func_00385CF8(&pose) = 1.0f;
    *func_00385D08(&pose) = 1.0f;
    *func_00385D18(&pose) = 0;
    *func_00386488(&frame) = 0.0f;
    *func_00386498(&frame) = 0.0f;
    *func_003864A8(&frame) = 0.0f;
    *func_00385D28(&pose) = 0;
    *func_003864B8(&frame) = 0.0f;
    *func_00385D38(&pose) = 0.5f;
    *func_003864C8(&frame) = 0.0f;
    *func_00385D78(&pose) = 0;
    *func_00386508(&frame) = 0.0f;
    *func_00385C98(&pose) = 0;
    *func_003864D8(&frame) = 0.0f;
    *func_003864E8(&frame) = 0.0f;
    *func_003864F8(&frame) = 0.0f;
    *func_00385DB8(&pose) = 0;
    *func_00386518(&frame) = 0.0f;
    if (kind == 1) {
        *func_00385CA8(&pose) = 0x1.921fb4p+0f;
        *func_00385DC8(&pose) = 0.5f;
    } else {
        *func_00385CA8(&pose) = 0.0f;
        *func_00385DC8(&pose) = 1.0f;
    }
    *func_00385DD8(&pose) = 0;
    *func_00385DE8(&pose) = 0;
    *func_00385DF8(&pose) = 0;
    *func_00386528(&frame) = 0.0f;
    *func_00386538(&frame) = 0.0f;
    *func_00385E18(&pose) = 0;
    *func_00385E28(&pose) = 0;
    *func_00385E38(&pose) = 0;
    *func_00386548(&frame) = 0.0f;
    *func_00386558(&frame) = 0.0f;
    *func_00385E58(&pose) = 0.0f;
    *func_00386568(&frame) = DRIVERSUPPORT_NAME__GetMotoristDynamicParameter() ? func_0044FA20(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter()) : 60.0f;
    *func_00386578(&frame) = 0.0f;
    *func_00385E68(&pose) = 0x1.999998p-4f;
    *func_00385E78(&pose) = 0x1.999998p-4f;
    *func_00386588(&frame) = 0.0f;
    *func_00386598(&frame) = 0.0f;
}
