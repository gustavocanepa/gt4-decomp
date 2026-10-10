typedef int s32;

extern "C" void func_0040AE20(float (*m)[4], const float *v, float *out) {
    for (s32 i = 0; i < 3; i++)
        out[i] = v[0] * m[0][i] + v[1] * m[1][i] + v[2] * m[2][i];
}
