typedef float f32;

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern "C" void func_00203160(Vec4 *arg0, Vec4 *arg1) {
    arg1->x = arg0->x;
    arg1->y = arg0->y;
    arg1->z = arg0->z;
    arg1->w = arg0->w;
}
