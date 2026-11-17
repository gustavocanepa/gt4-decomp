/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * func_0037DC78 (inferred): per-frame update of a chase/replay camera in the CameraSys unit.
 * With no subject (car->0x10) it only sets the defaults (near 100, fov 60) around the view
 * push/pop calls. Otherwise mode 0x1B0 asks the race object (dynamic_cast of owner->0x84) for a
 * view (virtual slot 0x430 or 0x450). The car's velocity (func_003FC698, scaled to per second)
 * drives the two smoothing filters at +0x18C/+0x198: a fixed fast setting when virtual 0x440
 * says so, else one proportional to the clamped speed. A valid view builds the look-at basis
 * (dir = pos - target, right = up x dir, up = dir x right), stores the eye in +0x1A4 and loads
 * it as the view matrix with the filtered roll/pitch; without one the subject model's own angles
 * and position are used. Byte 0x180 keeps whether the view was valid; a change clears byte
 * 0x16B.
 *
 * Source forms that decide the code: key (+0x188) read before the velocity call; vy/vz
 * pointers to the velocity's y/z kept alive to the final translate (no callee-saved register
 * is left, so reload rematerialises them as sp offsets, and at sched1 they lengthen the x
 * element's life so local-alloc gives retail's FP registers); last (+0x1A4) computed between the
 * two vector calls (it ends the post-call group of argument moves).
 */
#include "types.h"
#include "m2c_macros.h"

static inline float sqrt_(float x) { float r; __asm__ volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" void RacePS2Base__tf();
extern "C" void RaceBase__tf();
extern "C" char *__dynamic_cast_2(s32, void (*)(), int, char *, void (*)(), char *) throw();

struct RttiEntry { short adjustment, index; int typeInfo; };
static inline char *checkedRaceCast(char *object) {
    if (!object) return 0;
    RttiEntry *entry = *(RttiEntry **)(object + 0x64);
    return __dynamic_cast_2(entry->typeInfo, RacePS2Base__tf, 0, object + entry->adjustment, RaceBase__tf, object);
}

struct ViewInfo {
    s32 unk0;
    s32 valid;
    f32 pos[3];
    f32 target[3];
    f32 up[3];
    s32 enabled;
    f32 fov;
};

extern "C" s32 func_00379440(void);
extern "C" f32 func_0035C788(void *);
extern "C" void func_0036E950(f32 *, f32 *, f32 *);
extern "C" void func_0036E9D8(f32 *) throw();
extern "C" f32 func_00344798(void *, f32);
extern "C" f32 func_003447F8(void *, f32);
extern "C" f32 func_00344828(void *, f32);
extern "C" f32 func_00344858(void *, f32);
extern "C" f32 func_00344888(void *, f32);
extern "C" f32 func_003448B8(void *, f32);
extern "C" void func_00384A70(char *, s32, f32, f32);
extern "C" f32 func_00384B28(char *);
extern "C" void func_003FC698(char *, f32 *);
extern "C" void func_004A0690();
extern "C" void func_004A06F0();
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7454();
extern "C" void func_004A7550(char *);
extern "C" void func_004A7698(void *);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(f32);
extern "C" void func_004A79D8(f32);
extern "C" f32 func_005F5010(f32 *);
extern "C" void func_005F5040(f32 *, f32 *);
extern "C" void func_005F5268(f32 *, f32 *);

extern "C" s32 func_0037DC78(char *self, char *owner, s32 unused, char *car) {
    ViewInfo info;
    f32 pos[3];
    f32 target[3];
    f32 up[3];
    f32 dir[3];
    f32 right[3];
    f32 delta[3];
    f32 m[4][4];
    s32 active;
    s32 forced;
    char *race = 0;
    func_00379440();
    active = 0;
    u8 wasActive = M2C_FIELD(self, u8 *, 0x180);
    if (M2C_FIELD(owner, char **, 0x84))
        race = checkedRaceCast(M2C_FIELD(owner, char **, 0x84));
    char *subject = M2C_FIELD(car, char **, 0x10);
    M2C_FIELD(self, s64 *, 0x180) &= ~0xFFLL;
    f32 gain = 0.7f;
    forced = 0;
    if (!subject) {
        M2C_FIELD(self, f32 *, 8) = 100.0f;
        M2C_FIELD(self, f32 *, 0xC) = 60.0f;
        func_004A0690();
        func_004A53F8();
        func_004A7454();
        func_004A7550(self + 0x100);
        func_004A5400();
        func_004A06F0();
        return 1;
    }
    switch (M2C_FIELD(self, s32 *, 0x1B0)) {
    case 0: {
        char *e = M2C_FIELD(race, char **, 0x64) + 0x430;
        active = 0;
        M2C_FIELD(e, s32 (**)(char *, s32, ViewInfo *), 4)(race + M2C_FIELD(e, s16 *, 0), M2C_FIELD(car, s16 *, 0xC), &info);
        if (info.valid && info.enabled)
            active = 1;
        break;
    }
    case 1: {
        char *e = M2C_FIELD(race, char **, 0x64) + 0x450;
        active = 0;
        M2C_FIELD(e, s32 (**)(char *, s32, ViewInfo *), 4)(race + M2C_FIELD(e, s16 *, 0), M2C_FIELD(car, s16 *, 0xC), &info);
        if (info.valid)
            active = info.enabled != 0;
        break;
    }
    }
    if (active != wasActive)
        M2C_FIELD(self, s64 *, 0x168) &= 0xFFFFFFFF00FFFFFFLL;
    s32 key = M2C_FIELD(self, s32 *, 0x188);
    f32 *vel = pos;
    func_003FC698(car, vel);
    f32 *vy = &pos[1];
    f32 *vz = &pos[2];
    f32 k = 60.0f;
    vel[0] *= k;
    *vy *= k;
    *vz *= k;
    f32 speed2 = func_005F5010(vel);
    char *chaseB;
    char *chaseA;
    {
        char *e = M2C_FIELD(race, char **, 0x64) + 0x440;
        if (M2C_FIELD(e, s32 (**)(char *, s32), 4)(race + M2C_FIELD(e, s16 *, 0), M2C_FIELD(car, s16 *, 0xC))) {
            chaseA = self + 0x18C;
            func_00384A70(chaseA, key, 0x1.999998p-4f, 0x1.333332p-3f);
            chaseB = self + 0x198;
            gain = 1.4f;
            func_00384A70(chaseB, key, 0x1.999998p-4f, 0x1.333332p-3f);
            forced = 1;
        } else {
            f32 t = speed2 - 0x1.edd3bep+2f;
            if (t <= 0.0f)
                t = 0.0f;
            if (t >= 0x1.edd3bep+8f)
                t = 0x1.edd3bep+8f;
            f32 ratio = t / 0x1.edd3bep+8f;
            chaseA = self + 0x18C;
            chaseB = self + 0x198;
            func_00384A70(chaseA, key, ratio, -1.0f);
            func_00384A70(chaseB, key, ratio, -1.0f);
        }
    }
    char *model = M2C_FIELD(subject, char **, 0x18);
    f32 fov = 60.0f;
    f32 nearDist = 100.0f;
    func_0035C788(model);
    f32 dist = 0.0f;
    if (active) {
        s32 i;
        for (i = 0; i < 3; i++) {
            pos[i] = info.pos[i];
            target[i] = info.target[i];
            up[i] = info.up[i];
        }
        fov = info.fov * 180.0f / 0x1.921fb4p+1f;
        f32 *d = dir;
        func_005F5040(target, d);
        f32 *last = (f32 *)(self + 0x1A4);
        func_005F5268(d, pos);
        nearDist = sqrt_(func_005F5010(d));
        f32 *dy = &dir[1];
        f32 *dz = &dir[2];
        d[0] = -d[0];
        *dy = -*dy;
        *dz = -*dz;
        func_0036E9D8(d);
        func_0036E950(right, up, d);
        func_0036E9D8(right);
        func_0036E950(up, d, right);
        func_0036E9D8(up);
        func_005F5040(last, delta);
        func_005F5268(delta, pos);
        dist = sqrt_(func_005F5010(delta)) * 60.0f;
        func_005F5040(pos, last);
    }
    M2C_FIELD(self, f32 *, 8) = nearDist;
    M2C_FIELD(self, f32 *, 0xC) = fov;
    M2C_FIELD(self, s64 *, 0x180) = (M2C_FIELD(self, s64 *, 0x180) & ~0xFFLL) | active;
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    if (active) {
        if (dist > 0.5f || forced) {
            func_004A7988(func_00384B28(chaseA) * gain * fov / 80.0f);
            func_004A79B0(func_00384B28(chaseB) * gain * fov / 80.0f);
        }
        f32 (*pm)[4] = m;
        pm[0][0] = right[0];
        m[3][3] = 1.0f;
        m[1][0] = right[1];
        m[2][0] = right[2];
        m[0][1] = up[0];
        m[1][1] = up[1];
        m[2][1] = up[2];
        m[0][2] = dir[0];
        m[1][2] = dir[1];
        m[2][2] = dir[2];
        m[3][0] = 0;
        m[3][1] = 0;
        m[3][2] = 0;
        m[0][3] = 0;
        m[1][3] = 0;
        m[2][3] = 0;
        func_004A7698(pm);
        func_004A7844(-vel[0], -*vy, -*vz);
    } else {
        func_004A79D8(func_00344888(model, 0.0f) * 0x1.ca5dc0p+5f);
        func_004A7988(-func_00344858(model, 0.0f) * 0x1.ca5dc0p+5f);
        func_004A79B0(-func_003448B8(model, 0.0f) * 0x1.ca5dc0p+5f);
        f32 x = -func_00344798(model, 0.0f);
        f32 y = -func_003447F8(model, 0.0f);
        func_004A7844(x, y, -func_00344828(model, 0.0f));
    }
    func_004A7550(self + 0x100);
    func_004A5400();
    func_004A06F0();
    M2C_FIELD(self, s32 *, 0xEC) = 0;
    M2C_FIELD(self, s32 *, 0xE8) = 1;
    return 1;
}
