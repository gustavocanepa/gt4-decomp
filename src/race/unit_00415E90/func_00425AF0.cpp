struct Vec2 {
    float x;
    float y;
};

struct Mat3 {
    float m[9];
    void set(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8)
    {
        m[0] = a0;
        m[1] = a1;
        m[2] = a2;
        m[3] = a3;
        m[4] = a4;
        m[5] = a5;
        m[6] = a6;
        m[7] = a7;
        m[8] = a8;
    }
};

extern "C" void func_0057D8A0(float a, float *s, float *c);

extern "C" void func_00425AF0(Mat3 *out, Vec2 *p, float *angle)
{
    float sc[2];
    float a[4];
    a[0] = *angle;
    func_0057D8A0(a[0], &sc[0], &sc[1]);
    float c = sc[1];
    float s = sc[0];
    out->set(c, -s, 0.0f, s, c, 0.0f, -p->x * c - p->y * s, p->x * s - p->y * c, 1.0f);
}
