struct Mat4 {
    float m[16];
    void set(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7,
             float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15)
    {
        m[0] = a0;
        m[4] = a4;
        m[8] = a8;
        m[12] = a12;
        m[1] = a1;
        m[5] = a5;
        m[9] = a9;
        m[13] = a13;
        m[2] = a2;
        m[6] = a6;
        m[10] = a10;
        m[14] = a14;
        m[3] = a3;
        m[7] = a7;
        m[11] = a11;
        m[15] = a15;
    }
};
extern "C" void func_0057D8A0(float a, float *s, float *c);
static inline void sincos(const float &a, float *s, float *c) { func_0057D8A0(a, s, c); }

extern "C" void func_004252B8(Mat4 *m, const float *angle)
{
    float sc[4];
    float a = *angle;
    sincos(a, &sc[0], &sc[1]);
    float s = sc[0], c = sc[1];
    m->set(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, c, s, 0.0f, 0.0f, -s, c, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}
