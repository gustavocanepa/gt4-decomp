struct Vec3 {
    float v[3];
    float &operator[](int i) { return v[i]; }
    const float &operator[](int i) const { return v[i]; }
};

extern "C" void func_0036E950(Vec3 &out, const Vec3 &a, const Vec3 &b) {
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
}
