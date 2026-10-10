struct Mat3 {
    float m[9];
    void set(float a, float b, float c, float d, float e, float f, float g, float h, float i)
    {
        m[0] = a;
        m[3] = d;
        m[2] = c;
        m[1] = b;
        m[6] = g;
        m[7] = h;
        m[4] = e;
        m[5] = f;
        m[8] = i;
    }
};

extern "C" void func_0057D8A0(float *s, float *c, float a);

static inline void sincos(const float &a, float *s, float *c) { func_0057D8A0(s, c, a); }

extern "C" void func_00425348(Mat3 *r, const float *angle) {
    float sc[2];
    float a = *angle;
    sincos(a, &sc[0], &sc[1]);
    r->set(sc[1], 0.0f, -sc[0], 0.0f, 1.0f, 0.0f, sc[0], 0.0f, sc[1]);
}
