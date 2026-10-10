typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

extern "C" f32 func_004AC118(f32 y, f32 x);

extern "C" f32 func_0036EA50(Vec3 *v) {
    f32 h = v->x * v->x + v->z * v->z;
    __asm__("sqrt.s %0, %1" : "=f"(h) : "f"(h));
    return -func_004AC118(v->y, h) * 57.29578f;
}
