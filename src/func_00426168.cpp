typedef int u128 __attribute__((mode(TI)));
struct Mat {
    u128 r0, r1, r2, r3;
    Mat() {}
    Mat(const Mat &o) { r0 = o.r0; r1 = o.r1; r2 = o.r2; r3 = o.r3; }
    Mat &operator=(const Mat &o) { r0 = o.r0; r1 = o.r1; r2 = o.r2; r3 = o.r3; return *this; }
};
struct Vec;
extern "C" Mat func_00486C48(const Vec *v);
extern "C" void func_00425F50(Mat *m, const Vec *v);

extern "C" void func_00426168(Mat *out, const Vec *pos, const Vec *rot) {
    Mat m;
    *out = m = func_00486C48(rot);
    func_00425F50(out, pos);
}
