extern "C" float func_0036EAD8(float a);
extern "C" float func_0036EB98(float a, float b);

extern "C" float func_0036EC78(float from, float to, float t)
{
    float a = func_0036EAD8(from);
    float b = func_0036EAD8(to);
    return a + func_0036EB98(b, a) * t;
}
