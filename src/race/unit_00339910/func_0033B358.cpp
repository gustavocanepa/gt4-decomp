typedef int s32;

extern "C" void func_0033B358(float *out, s32 n, const float *a, const float *b, float t) {
    float u = 1.0f - t;
    for (s32 i = 0; i < n; i++)
        out[i] = a[i] * t + b[i] * u;
}
