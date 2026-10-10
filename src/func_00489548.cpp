struct Mat2 {
    float a, c, b, d; /* column major: (a c) is column 0 */
    Mat2 &operator=(const Mat2 &o)
    {
        a = o.a;
        c = o.c;
        b = o.b;
        d = o.d;
        return *this;
    }
};

extern "C" void func_00489548(Mat2 *m, const Mat2 *n)
{
    Mat2 t;
    t.a = m->a * n->a + m->b * n->c;
    t.c = m->c * n->a + m->d * n->c;
    t.b = m->a * n->b + m->b * n->d;
    t.d = m->c * n->b + m->d * n->d;
    *m = t;
}
