typedef float f32;

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern "C" void func_002030C0(Vec4 *arg0, Vec4 *arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
    arg0->w = arg1->w;
}
