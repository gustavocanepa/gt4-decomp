typedef int qword __attribute__((mode(TI)));
struct Vec { float x, y, z, w; } __attribute__((aligned(16)));

extern "C" void func_00488748(Vec *out, const Vec *v, const Vec *fallback) {
    if (v->x != 0.0f) {
        out->x = -v->y;
        out->y = v->x;
        out->z = 0.0f;
    } else {
        const float &y = v->y;
        if (y != 0.0f) {
            out->x = 0.0f;
            out->y = -v->z;
            out->z = y;
        } else if (v->z != 0.0f) {
            out->x = v->z;
            out->y = 0.0f;
            out->z = -v->x;
        } else {
            *(qword *)out = *(const qword *)fallback;
        }
    }
}
