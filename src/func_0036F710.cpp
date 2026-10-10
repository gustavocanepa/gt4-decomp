typedef float f32;

struct Curve_0036F710 {
    f32 x0, y0, x1, y1;
    f32 a, b, c;
};

extern "C" void func_0036F710(Curve_0036F710 *k, f32 x0, f32 y0, f32 x1, f32 y1) {
    f32 s0 = y0 / x0;
    f32 s1 = y1 / x1;
    k->x0 = x0;
    k->y0 = y0;
    k->x1 = x1;
    k->y1 = y1;
    k->a = s0 + s1 - 2.0f;
    k->b = s0 * -2.0f - s1 + 3.0f;
    k->c = s0;
}
