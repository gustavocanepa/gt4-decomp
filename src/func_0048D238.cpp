struct Vec3 { float x, y, z; };
struct Mat3;

extern "C" void func_0048D180(Vec3 *out, const Mat3 *m, const Vec3 *v);

extern "C" void func_0048D238(Vec3 *v, const Mat3 *m) {
    Vec3 t;
    func_0048D180(&t, m, v);
    v->x = t.x;
    v->y = t.y;
    v->z = t.z;
}
