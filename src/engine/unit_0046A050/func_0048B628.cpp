struct Quat { float x, y, z, w; };
extern "C" void func_0057D8A0(float a, float *s, float *c);

extern "C" void func_0048B628(Quat *q, float x, float y)
{
    float s1, c1, s2, c2;
    float hx = x * 0.5f;
    float hy = y * 0.5f;
    func_0057D8A0(hx, &s1, &c1);
    func_0057D8A0(hy, &s2, &c2);
    q->x = s1 * c2;
    q->y = -(s1 * s2);
    q->z = c1 * s2;
    q->w = c1 * c2;
}
