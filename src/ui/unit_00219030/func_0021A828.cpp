typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" void func_0021A828(char *arg0, Vec3 *arg1) {
    Vec3 *p = (Vec3 *)(arg0 + 0x30);

    p->x = arg1->x;
    p->y = arg1->y;
    p->z = arg1->z;
}
