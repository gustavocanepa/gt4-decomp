typedef float f32;
struct V2 {
    f32 x, y;
    f32 &operator[](int i) { return (&x)[i]; }
    const f32 &operator[](int i) const { return (&x)[i]; }
};
struct M2 { f32 a, b, c, d; };
extern "C" void func_004891E0(V2 *out, const M2 *m, const V2 *v) {
    f32 x = (*v)[0], y = (*v)[1];
    (*out)[0] = m->a * x + m->c * y;
    x = (*v)[0]; y = (*v)[1];
    (*out)[1] = m->b * x + m->d * y;
}