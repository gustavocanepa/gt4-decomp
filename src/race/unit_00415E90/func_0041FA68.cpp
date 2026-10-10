extern "C" float func_00420F00(void *v, float base);

extern "C" int func_0041FA68(float *out, void *v, int clamp)
{
    float ang[3];
    ang[0] = func_00420F00(v, -3.1415927f);
    float a = ang[0];
    if (a >= 0x1.69e954p+0f) {
        if (clamp) {
            *out = 0x1.69e954p+0f;
        }
        return 0;
    }
    if (a <= -0x1.69e954p+0f) {
        if (clamp) {
            *out = -0x1.69e954p+0f;
        }
        return 0;
    }
    *out = a;
    return 1;
}
