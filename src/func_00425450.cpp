struct Mat3 {
    float m[9];
    void set(float a, float b, float c, float d, float e, float f, float g, float h, float i)
    {
        m[0] = a;
        m[1] = b;
        m[6] = g;
        m[3] = d;
        m[4] = e;
        m[7] = h;
        m[2] = c;
        m[5] = f;
        m[8] = i;
    }
};
extern "C" void func_0057D8A0(float a, float *s, float *c);
static inline void sincos(const float &a, float *s, float *c) { func_0057D8A0(a, s, c); }

extern "C" void func_00425450(Mat3 *m, const float *angle)
{
    float sc[4];
    float a = *angle;
    sincos(a, &sc[0], &sc[1]);
    float s = sc[0], c = sc[1];
    m->set(c, s, 0.0f, -s, c, 0.0f, 0.0f, 0.0f, 1.0f);
}
