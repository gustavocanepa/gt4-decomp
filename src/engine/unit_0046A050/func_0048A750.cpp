typedef float f32;

struct Quat {
    f32 x, y, z, w;
};

struct Vec3 {
    f32 x, y, z;
};

extern "C" void func_0048A750(const Quat *q, Vec3 *out) {
    f32 x = q->x;
    f32 y = q->y;
    f32 z = q->z;
    f32 w = q->w;
    out->x = 2.0f * (x * z + y * w);
    out->y = 2.0f * (y * z - x * w);
    out->z = 2.0f * (0.5f - x * x - y * y);
}
