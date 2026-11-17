/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * func_0037D620 (inferred): per-frame update of a camera that plays a recorded camera path (a
 * CameraSys camera in the same unit as func_0037DC78). The frame counter at +0x18C counts down
 * and gives the play time (counter / 60); func_0037D5B0 turns it into the path step and its rate
 * (no rate while +0x140 < 2). Byte 0x1D0 picks the motion set (+0xD4 of the owner's motion data
 * when set, else +0xD0); without it, byte 0x1D1 mirrors the shot and step 1 switches to the
 * second stored pose. A new step clears byte 0x16B and restarts the track (+0x184, frame +0x190).
 * The sampled eye/target/up (default: origin looking down +z, y up) and field of view build a
 * look-at basis that is loaded as the view matrix, followed by the stored pose's angles and
 * position. When the counter runs out the camera reports state 3 and, outside 0x1D0 mode, sets
 * +0x1CC to 1.
 *
 * Source forms that decide the code: eye cleared with memset after the vector pointers and the
 * motion-data load; byte 0x1D0 read through an inline accessor in the mirror test (otherwise cse1
 * merges the two tests and threads the second away); pointer locals for up[1]/up[2] and
 * dir[1]/dir[2] that get no saved register (reload rematerialises them as sp offsets, but they
 * schedule the matrix as retail); the first-step constant set after the 0x1CC store.
 */
#include "types.h"
#include "m2c_macros.h"

static inline float sqrt_(float x) { float r; __asm__ volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

static inline void setVec3(f32 *v, f32 x, f32 y, f32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

struct Track {
    s32 id;
    f32 time;
};

struct PathSample {
    s32 valid;
    f32 eye[3];
    f32 target[3];
    f32 up[3];
    s32 hasFov;
    f32 fov;
};

extern "C" void *memset(void *, int, unsigned int);
extern "C" int func_0037D5B0(int mode, float *rate, float x);
extern "C" void func_003EBC10(Track *track, void *motion, int step, float rate);
extern "C" s32 func_003EBC88(Track *track, void *motion);
extern "C" void func_003EBCE8(Track *track, void *motion, s32 frame, PathSample *out);
extern "C" void func_0036E950(f32 *, f32 *, f32 *);
extern "C" void func_0036E9D8(f32 *) throw();
extern "C" void func_004A0690();
extern "C" void func_004A06F0();
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7454();
extern "C" void func_004A74B4(void *);
extern "C" void func_004A7550(char *);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(f32);
extern "C" void func_004A79D8(f32);
extern "C" f32 func_005F5010(f32 *);
extern "C" void func_005F5040(f32 *, f32 *);
extern "C" void func_005F5268(f32 *, f32 *);

static inline s32 replayMode(char *self) {
    return M2C_FIELD(self, u8 *, 0x1D0);
}

extern "C" s32 func_0037D620(char *self) {
    PathSample sample;
    f32 eye[3];
    f32 target[3];
    f32 up[3];
    f32 dir[3];
    f32 right[3];
    f32 rate;
    f32 m[4][4];
    s32 stepChanged;
    s32 useSecondPose;
    s32 mirrored = 0;
    f32 *e = eye;
    f32 *tg = target;
    f32 *u = up;
    f32 *uy = &up[1];
    char *motion = M2C_FIELD(M2C_FIELD(self, char **, 0x180), char **, 4);
    Track *track = (Track *)(self + 0x184);
    s32 step;
    f32 time = 0.0f;
    f32 nearDist = 1.0f;

    memset(e, 0, sizeof(eye));
    f32 fov = 60.0f;
    setVec3(tg, 0.0f, 0.0f, 1.0f);
    setVec3(u, 0.0f, 1.0f, 0.0f);
    stepChanged = 0;
    useSecondPose = 0;
    f32 *uz = &up[2];
    M2C_FIELD(self, f32 *, 0x1CC) = 0.0f;
    s32 firstStep = 1;
    if (M2C_FIELD(self, s32 *, 0x18C) >= 0) {
        s32 frames = M2C_FIELD(self, s32 *, 0x18C) - 1;
        M2C_FIELD(self, s32 *, 0x18C) = frames;
        time = frames / 60.0f;
    }
    step = func_0037D5B0(M2C_FIELD(self, u8 *, 0x1D0), &rate, time);
    if (M2C_FIELD(self, s32 *, 0x140) < 2)
        rate = 0.0f;
    if (!replayMode(self)) {
        mirrored = M2C_FIELD(self, u8 *, 0x1D1);
        if (step == firstStep) {
            useSecondPose = 1;
            mirrored = 0;
        }
    }
    if (replayMode(self)) {
        void *set = M2C_FIELD(motion, void **, 0xD4);
        func_003EBC10(track, set, step, rate);
        if (step != M2C_FIELD(self, s32 *, 0x194)) {
            M2C_FIELD(self, s64 *, 0x168) &= 0xFFFFFFFF00FFFFFFLL;
            stepChanged = 1;
            func_003EBC88(track, M2C_FIELD(motion, void **, 0xD4));
            M2C_FIELD(self, s32 *, 0x190) = 0;
        }
        func_003EBCE8(track, M2C_FIELD(motion, void **, 0xD4), M2C_FIELD(self, s32 *, 0x190), &sample);
    } else {
        void *set = M2C_FIELD(motion, void **, 0xD0);
        func_003EBC10(track, set, step, rate);
        if (step != M2C_FIELD(self, s32 *, 0x194)) {
            M2C_FIELD(self, s64 *, 0x168) &= 0xFFFFFFFF00FFFFFFLL;
            stepChanged = 1;
            func_003EBC88(track, M2C_FIELD(motion, void **, 0xD0));
            M2C_FIELD(self, s32 *, 0x190) = 0;
        }
        func_003EBCE8(track, M2C_FIELD(motion, void **, 0xD0), M2C_FIELD(self, s32 *, 0x190), &sample);
    }
    if (sample.valid) {
        s32 i;
        for (i = 0; i < 3; i++) {
            eye[i] = sample.eye[i];
            target[i] = sample.target[i];
            up[i] = sample.up[i];
        }
    }
    if (mirrored) {
        e[0] = -e[0];
        tg[0] = -tg[0];
        u[0] = -u[0];
    }
    if (sample.hasFov)
        fov = sample.fov * 180.0f / 0x1.921fb4p+1f;
    f32 *d = dir;
    func_005F5040(tg, d);
    func_005F5268(d, e);
    nearDist = sqrt_(func_005F5010(d));
    f32 *dy = &dir[1];
    f32 *dz = &dir[2];
    d[0] = -d[0];
    *dy = -*dy;
    *dz = -*dz;
    func_0036E9D8(d);
    f32 *r = right;
    func_0036E950(r, u, d);
    func_0036E9D8(r);
    func_0036E950(u, d, r);
    func_0036E9D8(u);
    M2C_FIELD(self, f32 *, 8) = nearDist;
    M2C_FIELD(self, f32 *, 0xC) = fov;
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    f32 (*pm)[4] = m;
    pm[0][0] = r[0];
    m[1][0] = right[1];
    m[2][0] = right[2];
    m[3][0] = 0;
    m[0][1] = u[0];
    m[1][1] = *uy;
    m[2][1] = *uz;
    m[3][1] = 0;
    m[0][2] = d[0];
    m[1][2] = *dy;
    m[2][2] = *dz;
    m[3][2] = 0;
    m[0][3] = 0;
    m[1][3] = 0;
    m[2][3] = 0;
    m[3][3] = 1.0f;
    func_004A74B4(pm);
    func_004A7844(-e[0], -eye[1], -eye[2]);
    if (useSecondPose) {
        const f32 &angle0 = M2C_FIELD(self, f32 *, 0x1BC);
        func_004A79D8(M2C_FIELD(self, f32 *, 0x1C4));
        func_004A7988(M2C_FIELD(self, f32 *, 0x1C0));
        func_004A79B0(angle0);
        func_004A7844(-M2C_FIELD(self, f32 *, 0x1B0), -M2C_FIELD(self, f32 *, 0x1B4), -M2C_FIELD(self, f32 *, 0x1B8));
    } else {
        const f32 &angle0 = M2C_FIELD(self, f32 *, 0x1A4);
        func_004A79D8(M2C_FIELD(self, f32 *, 0x1AC));
        func_004A7988(M2C_FIELD(self, f32 *, 0x1A8));
        func_004A79B0(angle0);
        func_004A7844(-M2C_FIELD(self, f32 *, 0x198), -M2C_FIELD(self, f32 *, 0x19C), -M2C_FIELD(self, f32 *, 0x1A0));
    }
    func_004A7550(self + 0x100);
    func_004A5400();
    func_004A06F0();
    M2C_FIELD(self, s32 *, 0xEC) = 0;
    if (stepChanged)
        M2C_FIELD(self, s64 *, 0x168) &= 0xFFFFFFFF00FFFFFFLL;
    if (M2C_FIELD(self, s32 *, 0x18C) < 0) {
        M2C_FIELD(self, s32 *, 0xE8) = 3;
        if (!M2C_FIELD(self, u8 *, 0x1D0))
            M2C_FIELD(self, f32 *, 0x1CC) = 1.0f;
    }
    M2C_FIELD(self, s32 *, 0x194) = step;
    return 1;
}
