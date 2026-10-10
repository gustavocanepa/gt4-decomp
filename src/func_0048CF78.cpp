struct Vec2 {
    float v[2];
    float operator[](int i) const { return v[i]; }
};

struct Mat2 {
    float m[4];
};

extern "C" void func_0048CF78(Vec2 *out, Mat2 *m, Vec2 *v) {
    out->v[0] = m->m[0] * (*v)[0] + m->m[2] * (*v)[1];
    out->v[1] = m->m[1] * (*v)[0] + m->m[3] * (*v)[1];
}
