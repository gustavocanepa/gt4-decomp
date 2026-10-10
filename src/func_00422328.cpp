typedef int s128 __attribute__((mode(TI)));

struct Vec_004222D0 {
    s128 q;
    Vec_004222D0() {}
    Vec_004222D0(const Vec_004222D0 &o) : q(o.q) {}
    Vec_004222D0 &operator=(const Vec_004222D0 &o) { q = o.q; return *this; }
};

extern "C" void func_004220D8(Vec_004222D0 *m);
extern "C" void func_0048D530(Vec_004222D0 *out, Vec_004222D0 *m, Vec_004222D0 *v);

static inline Vec_004222D0 mul(Vec_004222D0 *m, Vec_004222D0 *v) {
    Vec_004222D0 t;
    func_0048D530(&t, m, v);
    return t;
}
extern "C" Vec_004222D0 *func_00422328(Vec_004222D0 *arg0) {
    Vec_004222D0 m;
    func_004220D8(&m);
    *arg0 = mul(&m, arg0);
    return arg0;
}
