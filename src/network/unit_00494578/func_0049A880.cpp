typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

extern "C" void func_0049A880(Vec3 *v, f32 x, f32 y, f32 z) {
    f32 len2 = x * x + y * y + z * z;
    f32 inv;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(inv) : "f"(1.0f), "f"(len2));
    v->x = x * inv;
    v->y = y * inv;
    v->z = z * inv;
}
