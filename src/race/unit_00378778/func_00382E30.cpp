/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * func_00382E30 (inferred): per-frame update of a "watch the nearest car" camera in the CameraSys
 * unit. While no car is locked (+0x1B8 < 0) it scans the race's car list for the nearest other
 * car within 100 units of this car and locks it when it is closer than 20. A locked car further
 * than 30 is dropped; otherwise the heading towards it (minus this car's bank) becomes the yaw
 * target at +0x1BC, smoothed by the filter at +0x1C0 (copied to +0x2EC). The car's speed drives
 * the chase filters at +0x188/+0x194, its roll/pitch the sway filters at +0x1A0/+0x1AC. It then
 * pushes the view: the filters' pitch/yaw around the eye of the scene view (vcall 0x50 on
 * ctx->0x2880), then the car's own heading/pitch/bank in degrees and the negated car position
 * (0.2 above the origin), all stored back into the camera record.
 *
 * Source forms that decide the code: V/set/copy helpers and per-iteration V pointers as in
 * func_00382708 (the long-lived pointers leave no register for bestIdx and view, which are
 * spilled to 0x54/0x50); key read after the yaw filter store; chaseB computed between the two
 * func_00384A70 calls (ends the post-call group so the second call sets f13 before f12); the
 * degree conversions written in the calls and again in the final stores.
 */
#include "types.h"
#include "m2c_macros.h"

static inline float sqrt_(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" f32 func_00344798(void *, f32);
extern "C" f32 func_003447F8(void *, f32);
extern "C" f32 func_00344828(void *, f32);
extern "C" f32 func_00344858(void *, f32);
extern "C" f32 func_00344888(void *, f32);
extern "C" f32 func_003448B8(void *, f32);
extern "C" f32 func_00345198(void *);
extern "C" f32 func_003451A8(void *);
extern "C" f32 func_0036EA98(f32 *) throw();
extern "C" f32 func_0036EAD8(f32) throw();
extern "C" f32 func_0036EB98(f32, f32) throw();
extern "C" void func_00384A70(char *, s32, f32, f32);
extern "C" f32 func_00384B28(char *);
extern "C" void func_00384B70(char *, f32);
extern "C" void func_00384BC8(char *);
extern "C" void func_00384EE8(char *, s32, s32, f32, f32);
extern "C" void func_003FC618(char *, f32 *);
extern "C" void func_003FC698(char *, f32 *);
extern "C" void func_004A0690();
extern "C" void func_004A06F0();
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7454();
extern "C" void func_004A7550(char *);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(f32);
extern "C" void func_004A79D8(f32);
extern "C" f32 func_005F5010(f32 *);
extern "C" void func_005F5040(f32 *, f32 *);
extern "C" void func_005F5268(f32 *, f32 *);

struct V { f32 x, y, z; f32 &X() { return x; } f32 &Y() { return y; } f32 &Z() { return z; } };
static inline void set(V *p, f32 x, f32 y, f32 z) { p->X() = x; p->Y() = y; p->Z() = z; }
static inline void copy(V *out, V *in) { func_005F5040(&in->X(), &out->X()); }

static inline char *carModel(char *owner, s32 i) {
    return M2C_FIELD(M2C_FIELD(M2C_FIELD(owner, char **, 0x60), char ***, 8)[i], char **, 0x18);
}

extern "C" s32 func_00382E30(char *self, char *owner, s32 unused, char *car) {
    f32 here[3];
    V bestPos;
    V p;
    V d;
    V d2;
    char *ctx = M2C_FIELD(self, char **, 0x180);
    f32 best = 100.0f;
    char *obj = M2C_FIELD(ctx, char **, 0x2880);
    char *model = M2C_FIELD(ctx, char **, 0x18);
    char *e = M2C_FIELD(obj, char **, 8) + 0x50;
    char *view = M2C_FIELD(e, char *(**)(char *), 4)(obj + M2C_FIELD(e, s16 *, 0));
    s32 bestIdx = -1;
    func_003FC698(car, here);
    f32 *hy = &here[1];
    f32 *hz = &here[2];
    here[0] *= 60.0f;
    *hy *= 60.0f;
    *hz *= 60.0f;
    f32 speed2 = func_005F5010(here);
    func_003FC618(car, here);
    if (M2C_FIELD(self, s32 *, 0x1B8) < 0) {
        s32 count = *M2C_FIELD(owner, s32 **, 0x60);
        s32 i;
        for (i = 0; i < count; i++) {
            if (i != M2C_FIELD(car, s16 *, 0xC)) {
                V *pd = &d;
                V *pp = &p;
                char *m = carModel(owner, i);
                f32 x = func_00344798(m, 0.0f);
                f32 y = func_003447F8(m, 0.0f);
                f32 z = func_00344828(m, 0.0f);
                set(pp, x, y, z);
                copy(pd, pp);
                func_005F5268(&pd->X(), here);
                if (sqrt_(func_005F5010(&pd->X())) < best) {
                    best = sqrt_(func_005F5010(&pd->X()));
                    bestIdx = i;
                    copy(&bestPos, pp);
                }
            }
        }
        if (bestIdx >= 0 && best < 20.0f)
            M2C_FIELD(self, s32 *, 0x1B8) = bestIdx;
    }
    if (M2C_FIELD(self, s32 *, 0x1B8) >= 0) {
        V *pd = &d2;
        V *pp = &p;
        char *m = carModel(owner, M2C_FIELD(self, s32 *, 0x1B8));
        f32 x = func_00344798(m, 0.0f);
        f32 y = func_003447F8(m, 0.0f);
        f32 z = func_00344828(m, 0.0f);
        set(pp, x, y, z);
        copy(pd, pp);
        func_005F5268(&pd->X(), here);
        best = sqrt_(func_005F5010(&pd->X()));
        if (30.0f < best) {
            M2C_FIELD(self, s32 *, 0x1B8) = -1;
        } else {
            f32 roll = -func_003448B8(model, 0.0f) * 0x1.ca5dc0p+5f;
            M2C_FIELD(self, f32 *, 0x1BC) = func_0036EAD8(func_0036EB98(func_0036EA98(&pd->X()), roll));
        }
    }
    f32 yaw = 0.0f;
    if (M2C_FIELD(self, s32 *, 0x1B8) >= 0)
        yaw = M2C_FIELD(self, f32 *, 0x1BC);
    char *yawFilter = self + 0x1C0;
    func_00384EE8(yawFilter, M2C_FIELD(self, s32 *, 0x184), 1, yaw, 0.2f);
    M2C_FIELD(self, f32 *, 0x2EC) = *(f32 *)yawFilter;
    s32 key = M2C_FIELD(self, s32 *, 0x184);
    char *swayA = self + 0x1A0;
    char *swayB = self + 0x1AC;
    func_00384B70(swayA, func_00345198(model) * 0.5f);
    func_00384B70(swayB, 2.0f * func_003451A8(model));
    f32 t = speed2 - 0x1.edd3bep+2f;
    if (t <= 0.0f)
        t = 0.0f;
    if (t >= 0x1.edd3bep+8f)
        t = 0x1.edd3bep+8f;
    f32 ratio = t / 0x1.edd3bep+8f;
    char *chaseB;
    char *chaseA;
    chaseA = self + 0x188;
    func_00384A70(chaseA, key, ratio, -1.0f);
    chaseB = self + 0x194;
    func_00384A70(chaseB, key, ratio, -1.0f);
    f32 bank = func_003448B8(model, 0.0f);
    f32 pitch = func_00344858(model, 0.0f);
    f32 heading = func_00344888(model, 0.0f);
    f32 px = -func_00344798(model, 0.0f);
    f32 py = 0.2f - func_003447F8(model, 0.0f);
    f32 pz = -func_00344828(model, 0.0f);
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    f32 *eye = M2C_FIELD(view, f32 **, 0x44);
    func_00384BC8(swayA);
    func_00384BC8(swayB);
    f32 a = func_00384B28(chaseA) * 0.7f;
    f32 b = func_00384B28(chaseB) * 0.7f + M2C_FIELD(self, f32 *, 0x2EC);
    func_004A7988(a);
    func_004A79B0(b);
    func_004A7844(eye[0], eye[1], eye[2]);
    M2C_FIELD(self, f32 *, 0x4C) = b;
    M2C_FIELD(self, f32 *, 0x50) = a;
    M2C_FIELD(self, f32 *, 0x40) = eye[0];
    M2C_FIELD(self, f32 *, 0x44) = eye[1];
    M2C_FIELD(self, f32 *, 0x48) = eye[2];
    func_004A79D8(heading * 0x1.ca5dc0p+5f);
    func_004A7988(-pitch * 0x1.ca5dc0p+5f);
    func_004A79B0(-bank * 0x1.ca5dc0p+5f);
    func_004A7844(px, py, pz);
    func_004A7550(self + 0x100);
    func_004A5400();
    func_004A06F0();
    M2C_FIELD(self, f32 *, 0x34) = -bank * 0x1.ca5dc0p+5f;
    M2C_FIELD(self, f32 *, 0x38) = -pitch * 0x1.ca5dc0p+5f;
    M2C_FIELD(self, f32 *, 0x3C) = heading * 0x1.ca5dc0p+5f;
    M2C_FIELD(self, f32 *, 0x28) = px;
    M2C_FIELD(self, f32 *, 0x2C) = py;
    M2C_FIELD(self, f32 *, 0x30) = pz;
    return 1;
}
