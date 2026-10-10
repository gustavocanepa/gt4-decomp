typedef float f32;

struct Vec2_0048D000 {
    f32 a[2];
    const f32 &x() const { return a[0]; }
    const f32 &y() const { return a[1]; }
    f32 &x() { return a[0]; }
    f32 &y() { return a[1]; }
};

struct Mat_0048D000 {
    f32 m[9];
};

// Transforms v by the 2D affine matrix m (3x3, row-major columns). The first row reads x, forms its
// product, then reads y: the local statement order sets sched1's load order and with it the FP
// register ranks of v.x, v.y and m[6].
extern "C" void func_0048D000(Vec2_0048D000 *out, const Mat_0048D000 *m, const Vec2_0048D000 *v) {
    f32 vx = v->x();
    f32 p1 = m->m[0] * vx;
    f32 vy = v->y();
    f32 p2 = m->m[3] * vy;
    out->x() = p1 + p2 + m->m[6];
    out->y() = m->m[1] * v->x() + m->m[4] * v->y() + m->m[7];
}
