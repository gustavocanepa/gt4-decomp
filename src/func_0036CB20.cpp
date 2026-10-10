/* Wraps an angle into [-pi, pi]. */
static inline float absf(float x)
{
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" float func_0036CB20(float a)
{
    float n = (float)(int)((absf(a) + 3.14159265f) / 6.2831853f);
    if (a < 0.0f)
        return a + n * 6.2831853f;
    return a + n * -6.2831853f;
}
