typedef float f32;

struct Vec4_0022A910 {
    f32 x, y, z, w;
    Vec4_0022A910() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vec4_0022A910 &operator=(const Vec4_0022A910 &o) {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
            w = o.w;
        }
        return *this;
    }
};

extern "C" void func_0022A978(Vec4_0022A910 *out, void *a, const Vec4_0022A910 *in);

extern "C" void func_0022A910(Vec4_0022A910 *v, void *a) {
    Vec4_0022A910 t;
    func_0022A978(&t, a, v);
    *v = t;
}
