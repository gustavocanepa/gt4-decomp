/* Unit quaternion (x, y, z, w) to axis and angle: half = pi/2 - acos(w) with w clamped to [-1, 1],
   the axis is the vector part over sin(half) (zero when that is 0), the angle is 2 * half, and
   the sine is returned. Doubling the angle at the store keeps $f0 free for the return value. */
extern "C" float func_0059D2A0(float);
extern "C" float func_0057D2B8(float);
static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" float func_0048CE88(float *q, float *axis, float *angle) {
    float h = 1.5707963f;
    h -= func_0059D2A0(minf(maxf(q[3], -1.0f), 1.0f));
    float s = func_0057D2B8(h);
    int i = 1, j = 2;
    if (s != 0.0f) {
        float inv = 1.0f / s;
        axis[0] = q[0] * inv;
        axis[i] = q[i] * inv;
        axis[j] = q[j] * inv;
    } else {
        axis[0] = 0.0f;
        axis[1] = 0.0f;
        axis[2] = 0.0f;
    }
    *angle = h + h;
    return s;
}
