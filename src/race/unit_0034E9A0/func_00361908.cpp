/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;

struct Spec {
    u8 m0, m1, m2, m3, m4, m5;
    s8 m6;
    u8 m7, m8;
    char p9[0x12 - 9];
    short m12, m14, m16, m18, m1A, m1C, m1E, m20;
    u8 m22, m23, m24, m25, m26, m27, m28, m29, m2A, m2B, m2C, m2D;
    char p2E[0x30 - 0x2E];
    short m30[2];
    char p34[0x38 - 0x34];
    u8 m38, m39;
    short m3A;
    char p3C[0x40 - 0x3C];
    short m40;
    u8 m42, m43, m44;
    char p45[0x4C - 0x45];
    u8 m4C, m4D, m4E, m4F, m50;
    char p51[0x58 - 0x51];
    u8 m58[0x18];
    u8 m70[0x18];
    u8 m88[2];
    u8 m8A, m8B, m8C, m8D;
    u8 m8E[2];
    s8 m90[2];
    char p92[0x96 - 0x92];
    s8 m96, m97;
    u8 m98[2];
    short m9A, m9C;
    char p9E[0xA8 - 0x9E];
    u8 mA8;
    char pA9[0x112 - 0xA9];
    u8 m112;
    char p113[0x11C - 0x113];
    u8 m11C, m11D;
    short m11E;
    char p120[0x128 - 0x120];
    u8 m128, m129;
    char p12A[0x178 - 0x12A];
    u8 m178[3];
    char p17B[0x180 - 0x17B];
    u8 m180[3];
    char p183;
    struct { u8 x[6], y[6]; } m184[3];
    u8 m1A8[2];
    u8 m1AA[2];
    char p1AC[0x1B8 - 0x1AC];
    u8 m1B8;
    char p1B9;
    u8 m1BA, m1BB, m1BC, m1BD, m1BE, m1BF, m1C0, m1C1, m1C2, m1C3;
    char p1C4[0x1CE - 0x1C4];
    u8 m1CE[2];
    u8 m1D0[2][4];
    u8 m1D8[2][4];
    char p1E0[0x1E4 - 0x1E0];
    u8 m1E4[2];
    char p1E6[0x210 - 0x1E6];
    u8 m210;
};

struct Axle {
    char p0[8];
    float m8, mC;
    char p10[0x38 - 0x10];
    float m38;
    char p3C[0x44 - 0x3C];
    float m44;
    char p48[0x58 - 0x48];
};

struct Table { float m0[3]; float m4[6]; float m8[6]; };
struct Curve { char p[0xC]; };

union Pair { u8 b[4]; unsigned w; };
struct Aero;
struct Aero {
    float m0, m4, m8;
    Pair mC;
    float m10, m14, m18;
    Pair m1C;
    float m20, m24, m28, m2C;
    u8 m30, m31, m32, m33;
};
struct AeroData { char p[0x14]; float m14; char p18[0x30 - 0x18]; float m30; char p34[0x70 - 0x34]; float m70, m74; };

struct Car {
    float m0, m4, m8, mC, m10, m14, m18, m1C, m20, m24;
    float m28[2];
    u8 m30, m31, m32, m33;
    float m34, m38, m3C, m40, m44, m48, m4C, m50, m54;
    Table tables[3];
    float m10C, m110, m114, m118, m11C, m120, m124, m128, m12C, m130;
    char m134[0x234 - 0x134];
    u8 m234[0x2C4 - 0x234];
    float m2C4[2];
    char p2CC[0x2D4 - 0x2CC];
    float m2D4[2];
    char p2DC[0x308 - 0x2DC];
    Axle axles[2];
    Curve m3B8[2];
    char p3D0[0x3D0 - 0x3D0];
    float m3D0[2][4];
    float m3F0[2][4];
    char p410[0xFC8 - 0x410];
    float mFC8, mFCC;
    float mFD0[2];
    char pFD8[0xFE4 - 0xFD8];
    float mFE4[2];
    float mFEC[2];
    float mFF4[2];
    float mFFC[2];
    float m1004;
    float m1008[2];
    float m1010[3];
    char p101C[0x1024 - 0x101C];
    float m1024[2];
    float m102C[2];
    float m1034[2];
    float m103C, m1040, m1044;
    short m1048;
    char p104A;
    u8 m104B;
    float m104C, m1050, m1054, m1058, m105C, m1060, m1064, m1068, m106C, m1070;
    char p1074[2];
    u8 m1076, m1077;
    float m1078, m107C, m1080, m1084;
    float m1088[2];
    float m1090[2];
    Aero m1098;
    char p10CC[0x10CC - 0x10CC];
    float m10CC;
    u8 m10D0, m10D1, m10D2, m10D3;
    float m10D4, m10D8;
};

struct Setup { u8 m0[3]; u8 m3; u8 front[4]; u8 rear[4]; };
struct Options { char p0[3]; u8 m3, m4; char p5[7 - 5]; u8 m7; char p8[0xA - 8]; u8 mA;
                 char pB[0xBC - 0xB]; u8 mBC, mBD; char pBE[0x118 - 0xBE]; u8 m118, m119; };
struct AxleCount { char p0[4]; u8 front, rear; };

extern Options D_00620CD8;
extern float D_00622308;

extern "C" {
void func_0034ACA8(Spec *, u8 *, char *, int);
void func_0034EF30(char *, Spec *, int, int);
u8 func_003594E0(Spec *);
AxleCount *func_00359510(Car *);
float func_00359568(Curve *, float);
int func_00359A38(Curve *, int, float *, float *, int, int);
AeroData *func_00359F38(Car *);
int func_0035A058(Spec *);
int func_00360468(float *, float *, float *, int, u8 *, u8 *);
void func_00360780(Car *, Spec *, char *, int);
void func_00360A78(void);
void func_00360B60(Axle *, u8 *, u8, int);
void func_00360DC8(Car *, Axle *, Spec *, int, int);
void func_00361570(Car *, Spec *, int, int);
void func_00361798(Car *, int, int);
void func_0036CD98(Spec *, Car *);
int func_00466B28(int, int);
float func_0057D118(float, float);
float func_0057D2B8(float);
}

/* Builds the runtime car block from a car spec record (inferred): masses, wheelbase and track,
 * centre of gravity, per-axle tables, steering curves, aero flags and tyre/brake constants,
 * applying the setup's per-axle scales when mode == 2. Called by the race (re)initialisation
 * func_00363B10. */
extern "C" int func_00361908(Car *car, Spec *spec, int mode, int variant, Setup *setup, char *extra) {
    int scale[2];
    float mass2;
    float front;

    car->m33 = spec->m23;
    car->m10D3 = 0;
    if (spec->m210 >= 150) car->m10D3 = 1;
    car->m32 = spec->m1;
    car->m30 = func_003594E0(spec);
    if (spec->m3 == 0) {
        u8 v = 1;
        switch (spec->m128) {
        case 3: v = 2; break;
        case 4: v = 3; break;
        }
        car->m10D2 = v;
    } else car->m10D2 = spec->m3;
    car->m1076 = spec->mA8;
    if (spec->m128 >= 5) spec->m128 = 0;
    car->m1048 = spec->m20;
    if (spec->m20 == 0) car->m48 = 1200.0f;
    else car->m48 = (float)spec->m20;
    {
        u8 pct = spec->m8;
        if (pct != 0 && pct != 100) {
            car->m48 *= (float)pct / 100.0f;
            car->m1048 = car->m1048 * pct / 100;
        }
    }
    mass2 = 0.0f;
    front = (float)spec->m22 * 0x1.47ae14p-7f;
    car->m0 = (float)spec->m12 * 0x1.0624dcp-10f;
    car->m4 = (float)spec->m14 * 0x1.0624dcp-10f;
    car->m18 = (float)spec->m1A * 0x1.0624dcp-10f;
    if (func_0035A058(spec)) car->m18 = func_00359F38(car)->m74;
    if (spec->m5) {
        float m = car->m48;
        float add = (float)spec->m5;
        float pos = (float)(50 - spec->m6) * 0x1.47ae14p-7f;
        float len = car->m18;
        float f0 = front;
        float total = m + add;
        car->m48 = total;
        car->m1048 += spec->m5;
        front = (m * f0 + add * pos) / total;
        {
            float d0 = len * (front - pos);
            float d1 = len * (f0 - front);
            mass2 = m * d1 * d1 + add * d0 * d0;
        }
    }
    {
        float rear = 1.0f - front;
        float a = car->m18 * front;
        float b;
        car->m24 = front;
        b = car->m18 - a;
        car->m14 = a;
        car->m20 = rear;
        car->m10 = b;
        car->m50 = -(b - a) * 0.5f;
        if (func_0035A058(spec)) {
            AeroData *aero = func_00359F38(car);
            car->m50 = -(aero->m14 * rear + aero->m70 * front);
        }
    }
    car->m0 = car->m0 - car->m50;
    car->m4 = car->m4 + car->m50;
    car->m8 = (float)spec->m16 * 0x1.0624dcp-10f;
    car->m28[0] = (float)(spec->m1C - spec->m96 * 2) * 0x1.0624dcp-10f * 0.5f;
    car->m28[1] = (float)(spec->m1E - spec->m97 * 2) * 0x1.0624dcp-10f * 0.5f;
    car->mC = (float)spec->m18 * 0x1.0624dcp-10f;
    if (car->m234[0] == 7) car->m48 += (float)D_00620CD8.m3;
    else car->m48 += (float)(D_00620CD8.m3 + D_00620CD8.m4);
    func_0034EF30(car->m134, spec, setup->m3 * 10, variant);
    func_0034ACA8(spec, car->m234, car->m134, variant);
    car->m104C = (float)spec->m112;
    car->m104B = spec->m11C;
    for (int i = 0; i < 2; i++) {
        short w = spec->m30[i];
        u8 k = spec->m1E4[i];
        if (k != 0 && k != 100 && w != 0) {
            float x = car->m28[i];
            float t = x + car->m2D4[i] * 0.5f;
            float lim = (float)w * 0x1.0624dcp-10f * 0.5f;
            if (lim < t) car->m28[i] = x - (t - lim);
        }
    }
    car->m1C = 2.0f * (car->m28[0] * car->m24 + car->m28[1] * (1.0f - car->m24));
    car->m10D4 = (float)spec->m11D * 0x1.47ae14p-7f;
    car->m10D8 = (float)(spec->m11E * 100);
    func_0036CD98(spec, car);
    car->m31 = func_00466B28(spec->m128, spec->m129);
    {
        int v = D_00620CD8.m118;
        if (v == 0) v = 50;
        car->mFCC = 0x1.921fb2p+0f / ((float)v * 0x1.1c71c6p-2f);
        v = D_00620CD8.m119;
        if (v == 0) v = 50;
        car->mFC8 = 1.0f / ((float)v * 0x1.1c71c6p-2f);
    }
    func_00361570(car, spec, 0, variant);
    for (int i = 0; i < 2; i++) {
        int n = spec->m1CE[i];
        int j;
        for (j = 0; j < n; j++) {
            int angle = 0x80 - spec->m1D0[i][j];
            u8 ratio = spec->m1D8[i][j];
            car->m3D0[i][n - 1 - j] = (float)angle * 0x1.1df468p-4f * 0.03125f;
            car->m3F0[i][n - 1 - j] = (float)ratio / 200.0f;
        }
        func_00359A38(&car->m3B8[i], n, car->m3D0[i], car->m3F0[i], 0, 0);
    }
    for (int i = 0; i < 2; i++) {
        float lo = (float)D_00620CD8.mBC * 0x1.87fffep+6f;
        float range = (float)D_00620CD8.mBD * 0x1.87fffep+6f - lo;
        car->m1088[i] = lo - range;
        car->m1090[i] = range / (car->m2D4[i] * 0x1.323ffep+13f);
    }
    scale[0] = spec->m2A;
    scale[1] = spec->m2B;
    for (int i = 0; i < 2; i++) car->mFD0[i] = (float)(scale[i] + 900) * 0x1.0624dcp-10f;
    if (mode == 2) {
        scale[0] = setup->front[car->m31];
        scale[1] = setup->rear[car->m31];
        for (int i = 0; i < 2; i++) {
            if (scale[i] == 0) scale[i] = 100;
            car->mFD0[i] *= (float)scale[i] * 0x1.47ae14p-7f;
        }
    }
    {
        float k;
        if (spec->m40 != 0) {
            k = (float)spec->m40 / 10000.0f;
            k *= D_00622308 * 0.5f;
        }
        else k = car->m8 * car->mC * D_00622308 * 0.5f;
        car->m1064 = (float)spec->m42 * 0x1.47ae14p-7f;
        car->m1068 = k * car->m1064;
        car->m106C = k * ((float)spec->m43 * 0x1.47ae14p-7f);
        car->m1070 = k * ((float)spec->m44 * 0x1.47ae14p-7f);
        car->m1077 = spec->m4C;
        if (car->m1077) {
            car->m1078 = (float)spec->m4D * 0x1.1c71c6p-2f;
            car->m107C = (float)spec->m4E * 0x1.1c71c6p-2f;
            {
                u8 t = spec->m4F;
                if (t == 0) car->m1080 = 300.0f;
                else car->m1080 = 10.0f / (float)t;
            }
            car->m1084 = k * ((float)spec->m50 * 0x1.47ae14p-7f);
            if (car->m1077 == 7) car->m1084 = (float)spec->m50 * 0x1.87fffep+6f;
        } else {
            car->m1078 = 0.0f;
            car->m107C = 0.0f;
            car->m1080 = 0.0f;
            car->m1084 = 0.0f;
        }
    }
    {
        float r = (float)D_00620CD8.mA * 0x1.0624dcp-10f;
        car->m1068 += (car->m106C + car->m1070) * r;
    }
    for (int i = 0; i < 2; i++) {
        u8 c = spec->m178[i];
        car->m1010[i] = (float)(c * 10) * 0x1.399998p+3f;
        car->m1024[i] = (float)spec->m1A8[i] * 0x1.999998p-4f;
        car->m102C[i] = (float)spec->m1AA[i] * 0x1.47ae14p-7f;
        if (c == 0) car->m1034[i] = 0.0f;
        else car->m1034[i] = car->m2C4[i] / car->m1010[i];
    }
    car->m1010[2] = (float)(spec->m178[2] * 10) * 0x1.399998p+3f;
    car->m10D0 = spec->m2C;
    car->m10CC = (float)spec->m2D * 0x1.47ae14p-7f;
    {
        Aero *a = &car->m1098;
        u8 flags = spec->m1B8;
        a->m0 = (float)spec->m1BA * 0x1.47ae14p-7f;
        a->m4 = (float)spec->m1BB * 0x1.47ae14p-7f;
        a->m8 = (float)spec->m1BC * 0x1.47ae14p-7f;
        a->mC.b[0] = flags & 1 ? 1 : 0;
        a->mC.b[1] = flags >> 1 & 1;
        a->mC.b[2] = flags >> 2 & 1;
        a->mC.b[3] = flags >> 3 & 1;
        a->m30 = (a->mC.w & 0xFFFF) && a->m0 != 0.0f;
        a->m31 = (a->mC.w & 0xFFFF0000) && a->m8 != 0.0f;
        a->m10 = (float)spec->m1BD * 0x1.47ae14p-7f;
        a->m14 = (float)spec->m1BE * 0x1.47ae14p-7f;
        a->m18 = (float)spec->m1BF * 0x1.47ae14p-7f;
        a->m1C.b[0] = flags >> 4 & 1;
        a->m1C.b[1] = flags >> 5 & 1;
        a->m1C.b[2] = flags >> 6 & 1;
        a->m1C.b[3] = flags >> 7;
        a->m32 = (a->m1C.w & 0xFFFF) && a->m10 != 0.0f;
        a->m33 = (a->m1C.w & 0xFFFF0000) && a->m18 != 0.0f;
        a->m24 = (float)spec->m1C0 * 0x1.999998p-4f;
        a->m28 = (float)spec->m1C1 * 0x1.47ae14p-7f;
        a->m20 = (float)spec->m1C2 * 0x1.999998p-4f;
        if (spec->m1C3 == 100 || spec->m1C3 == 0) a->m2C = 1.0f;
        else a->m2C = (float)spec->m1C3 * 0x1.47ae14p-7f;
    }
    car->m54 = (float)spec->m28 * 0x1.1df468p-6f;
    func_00360468(car->tables[0].m0, car->tables[0].m4, car->tables[0].m8, spec->m180[0], spec->m184[0].x, spec->m184[0].y);
    func_00360468(car->tables[1].m0, car->tables[1].m4, car->tables[1].m8, spec->m180[2], spec->m184[2].x, spec->m184[2].y);
    func_00360468(car->tables[2].m0, car->tables[2].m4, car->tables[2].m8, spec->m180[1], spec->m184[1].x, spec->m184[1].y);
    {
        float len = car->m18, w = car->m28[0];
        car->m10C = func_0057D118(len, len - w) / 0x1.921fb2p-1f;
        car->m110 = func_0057D118(len, len + w) / 0x1.921fb2p-1f;
    }
    if (spec->m29 == 0) car->m1004 = 0.0f;
    else {
        float x = (float)spec->m29 * 0x1.1df468p-6f;
        if (func_0035A058(spec)) x = func_00359F38(car)->m30;
        car->m1004 = func_0057D2B8(x);
    }
    for (int i = 0; i < 2; i++) {
        car->m1008[i] = func_0057D118((float)(spec->m8E[i] - 0x80) * 0.5f * 0x1.0624dcp-10f, car->m2C4[i]);
        car->mFE4[i] = -((float)spec->m88[i] * 0x1.999998p-4f * 0x1.1df468p-6f);
        car->mFEC[i] = (float)spec->m90[i] * 0x1.1df468p-6f;
        car->mFF4[i] = func_00359568(&car->m3B8[i], car->mFE4[i]);
        car->mFFC[i] = (float)spec->m98[i] * 0x1.47ae14p-7f;
    }
    {
        float rate = 6000.0f;
        float k1, k2;
        if (spec->m24 == 0) car->m114 = rate;
        else car->m114 = rate = (float)spec->m24 * 100.0f;
        if (spec->m5) car->m114 = rate + mass2;
        car->m118 = 1.0f / rate;
        if (spec->m25 == 0) k1 = 4000.0f;
        else k1 = (float)spec->m25 * 100.0f;
        car->m11C = car->m10 / k1;
        car->m120 = car->m14 / k1;
        if (spec->m26 == 0) k2 = 2000.0f;
        else k2 = (float)spec->m26 * 100.0f;
        car->m124 = car->m28[0] / k2;
        car->m128 = car->m28[1] / k2;
        func_00360A78();
        func_00360B60(&car->axles[0], spec->m58, spec->m8C, variant);
        func_00360B60(&car->axles[1], spec->m70, spec->m8D, variant);
        if (spec->m9A == 0) car->m40 = (float)spec->m8A * 0x1.0624dcp-10f;
        else car->m40 = (float)spec->m9A * 0x1.0624dcp-10f;
        if (spec->m9C == 0) car->m44 = (float)spec->m8B * 0x1.0624dcp-10f;
        else car->m44 = (float)spec->m9C * 0x1.0624dcp-10f;
        {
            float cg;
            if (car->m1077 == 7) {
                float d = car->m40 - car->m44;
                if (d < 0.0f) d = -d;
                if (d > 0x1.eb851ep-6f) {
                    car->m1084 = 0.0f;
                    car->m1077 = 0;
                }
            }
            cg = car->m40 * car->m24 + car->m44 * car->m20;
            car->m3C = cg;
            car->m1060 = (float)spec->m27 * 0x1.0624dcp-10f;
            car->m103C = car->m48 * 0x1.399998p+3f;
            {
                float t = (car->m1060 + cg) * 0.5f;
                car->m34 = t / car->m1C;
                car->m38 = t / car->m18;
            }
        }
        {
            AxleCount *ac = func_00359510(car);
            float sprung;
            if (ac->front == 2 && ac->rear == ac->front)
                sprung = car->m48 - 2.0f * (car->axles[0].m38 + car->axles[1].m38);
            else
                sprung = car->m48 - (car->axles[0].m38 * (float)ac->front + car->axles[1].m38 * (float)ac->rear);
            if (!(sprung <= 0.0f)) {
                float wgt = sprung * 0x1.399998p+3f;
                AxleCount *n;
                car->m4C = sprung;
                car->m34 = sprung * car->m34;
                car->m38 = sprung / car->m48 * car->m38;
                car->m1040 = wgt * car->m24;
                car->m1044 = wgt * car->m20;
                n = func_00359510(car);
                car->m1050 = (float)spec->m38;
                car->m1054 = (float)spec->m39;
                {
                    float wf, wr;
                    if (spec->m3A == 0) {
                        wf = car->m1040;
                        wr = car->m1044;
                    } else {
                        float f = (float)spec->m3A * 0x1.399998p+3f;
                        wf = f * car->m24;
                        wr = f * car->m20;
                    }
                    car->m1058 = (float)n->front / wf;
                    car->m105C = (float)n->rear / wr;
                }
            }
        }
        {
            float a = car->m10, b = car->m14;
            float t = (float)D_00620CD8.m7 * 0x1.47ae14p-7f;
            car->m12C = t / (k1 + car->m48 * a * a);
            car->m130 = t / (k1 + car->m48 * b * b);
        }
    }
    func_00361798(car, 0, variant);
    for (int i = 0; i < 2; i++) func_00360DC8(car, &car->axles[i], spec, i, variant);
    {
        float f = car->axles[0].m8, r = car->axles[1].m8;
        float df = car->axles[0].mC - f;
        float dr;
        car->axles[0].m44 = f;
        dr = car->axles[1].mC - r;
        car->axles[1].m44 = r;
        if (dr < df) car->axles[1].m44 = r - (df - dr);
        else if (df < dr) car->axles[0].m44 = f - (dr - df);
    }
    func_00360780(car, spec, extra, variant);
    return 0;
}
