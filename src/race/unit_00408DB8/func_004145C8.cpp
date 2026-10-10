extern "C" float D_00622A20[11];

static inline const float &table(int i) { return D_00622A20[i]; }

extern "C" float func_004145C8(float t, float scale) {
    float r;
    if (t <= 0.0f) {
        r = D_00622A20[0];
    } else if (1.0f <= t) {
        r = D_00622A20[10];
    } else {
        t *= 10.0f;
        int i = (int)t;
        float f = t - (float)i;
        r = table(i) * (1.0f - f) + table(i + 1) * f;
    }
    return r * scale;
}
