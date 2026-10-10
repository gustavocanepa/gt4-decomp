typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

struct Rect {
    f32 x0, y0, x1, y1;
};

extern "C" int func_0049B330(const Vec3 *a, const Vec3 *b);

extern "C" bool func_0047DFB0(const Rect *r) {
    Vec3 a;
    Vec3 b;
    a.x = r->x0;
    a.y = r->y0;
    a.z = 0.0f;
    b.x = r->x1;
    b.y = r->y1;
    b.z = 0.0f;
    return func_0049B330(&a, &b) != 0;
}
