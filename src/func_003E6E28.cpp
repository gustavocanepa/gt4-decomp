typedef int s32;
typedef float f32;

extern "C" void func_003E6E28(f32 *out, const f32 *p, const f32 *d, s32 axis, f32 t) {
    f32 s = (t - p[axis]) / d[axis];
    out[0] = p[0] + d[0] * s;
    out[1] = p[1] + d[1] * s;
    out[2] = p[2] + d[2] * s;
}
