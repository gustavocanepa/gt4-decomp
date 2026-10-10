extern "C" float func_0036EAD8(float a)
{
    int n;
    if (a >= 360.0f) {
        n = (int)(a / 360.0f);
        a -= n * 360.0f;
    }
    if (a < 0.0f) {
        a = -a;
        n = (int)(a / 360.0f);
        a -= n * 360.0f;
        a = 360.0f - a;
    }
    return a;
}
