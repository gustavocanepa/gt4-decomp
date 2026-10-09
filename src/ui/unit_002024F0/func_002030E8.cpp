typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" Vec4 *func_002030E8(Vec4 *arg0, Vec4 *arg1) {
    if (arg0 != arg1) {
        arg0->x = arg1->x;
        arg0->y = arg1->y;
        arg0->z = arg1->z;
        arg0->w = arg1->w;
    }
    return arg0;
}
