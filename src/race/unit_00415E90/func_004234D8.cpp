struct V2 {
    float x, y;
};

struct Angle {
    float v;
};

extern "C" float func_0059D2A0(float x);

static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float clampf(const float &v, float lo, float hi) { return minf(maxf(v, lo), hi); }

extern "C" Angle *func_004234D8(Angle *out, const V2 *a, const V2 *b) {
    float bx = b->x, ax = a->x, by = b->y, ay = a->y;
    float d = ax * bx + ay * by;
    out->v = 0x1.921fb4p0f - func_0059D2A0(clampf(d, -1.0f, 1.0f));
    return out;
}
