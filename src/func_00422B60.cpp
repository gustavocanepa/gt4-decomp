static inline bool positive(float x) { return 0.0f < x; }
static inline bool isZero(float x) { return x == 0.0f; }

extern "C" int func_00422B60(float x) {
    float f = (float)(int)x;
    float r = f;
    if (positive(x) || isZero(x - f))
        return (int)r + 1;
    return (int)r;
}
