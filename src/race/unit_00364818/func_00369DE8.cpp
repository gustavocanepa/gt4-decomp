typedef unsigned char u8;

#define F(b, o) (*(float *)((b) + (o)))

extern "C" float func_00369B48(u8 *prm, float v, int mode);
extern "C" float func_003F2650(u8 *p, int arg, float v);

extern "C" void func_00369DE8(u8 *p, u8 *st, u8 *prm, int arg3, int mode, float x, float k)
{
    u8 *s = p + 0x104;
    float lim;
    float pos;
    float dt;

    lim = F(prm, 0x8);
    if (*(unsigned short *)(s + 0x4BA) != 0)
        lim = F(prm, 0x44);
    dt = F(p, 0x54C);
    pos = F(st, 0x94) + (F(st, 0x98) + (F(st, 0x9C) + F(st, 0xA0)) / F(prm, 0x38) * 0.5f * dt) * dt;
    if (lim < pos)
        pos = lim;
    else if (pos < F(prm, 0x4))
        pos = F(prm, 0x4);

    if (pos < x) {
        float r;
        x = pos;
        F(st, 0x9C) = -x * k;
        if (x == lim) {
            F(st, 0x98) = 0.0f;
        } else {
            r = F(s, 0x44C) * (x - F(st, 0x94));
            F(st, 0x98) = r;
            if (1.0f < r)
                F(st, 0x98) = 1.0f;
            else if (r < -1.0f)
                F(st, 0x98) = -1.0f;
        }
        F(st, 0xA0) = func_00369B48(prm, F(st, 0x98), mode);
        F(st, 0x94) = pos;
        F(st, 0x48) = 0.0f;
    } else {
        float lo;
        float d, a, b, r;
        lo = (x < F(prm, 0x4)) ? F(prm, 0x4) : x;
        d = lo - F(prm, 0x0);
        a = -lo * k;
        if (d < 0.0f)
            a += d * d * F(prm, 0x34);
        r = F(s, 0x44C) * (x - F(st, 0x94));
        F(st, 0x98) = r;
        b = func_00369B48(prm, r, mode);
        if (r < 0.0f && d < 0.0f) {
            if (r < -1.0f)
                r = -1.0f;
            b -= F(prm, 0x40) * r;
        }
        if ((*(u8 **)(p + 0x10))[0x1076] != 0)
            b += func_003F2650(p, arg3, lo);
        F(st, 0x94) = lo;
        F(st, 0x9C) = a;
        F(st, 0xA0) = b;
        {
            float t = a + b + F(prm, 0x3C);
            F(st, 0x48) = t;
            if (t < 0.0f) {
                F(st, 0x9C) = -F(prm, 0x3C);
                F(st, 0xA0) = 0.0f;
                F(st, 0x48) = 0.0f;
            }
        }
    }
}
