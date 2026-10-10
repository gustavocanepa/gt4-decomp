struct Vec2 { float x, y; };
extern "C" void func_0057D8A0(float a, float *s, float *c);
static inline void sincos(const float &a, float *s, float *c) { func_0057D8A0(a, s, c); }

extern "C" void func_004255F8(Vec2 *out, const float *angle, const Vec2 *in)
{
    float sc[4];
    float a = *angle;
    sincos(a, &sc[0], &sc[1]);
    float c = sc[1], s = sc[0];
    float y = in->y, x = in->x;
    out->x = x * c - y * s;
    out->y = x * s + y * c;
}
