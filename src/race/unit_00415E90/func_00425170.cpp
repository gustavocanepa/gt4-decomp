struct Angle { float rad; Angle(const Angle &o) : rad(o.rad) {} };
struct Mat2 { float m[4]; };

extern "C" void func_0057D8A0(float *s, float *c, float rad);

extern "C" void func_00425170(Mat2 *out, const Angle *angle)
{
    float s, c;
    Angle a = *angle;
    func_0057D8A0(&s, &c, a.rad);
    out->m[0] = c;
    out->m[1] = s;
    out->m[2] = -s;
    out->m[3] = c;
}
