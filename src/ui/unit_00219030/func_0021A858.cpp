typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" void func_0021A858(char *arg0, Vec3 *arg1) {
    Vec3 *dst = (Vec3 *)(arg0 + 0x3C);
    dst->x = arg1->x;
    dst->y = arg1->y;
    dst->z = arg1->z;
}
