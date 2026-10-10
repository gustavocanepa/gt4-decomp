struct Vec3 {
    float v[3];
    float &operator[](int i) { return v[i]; }
};

struct Vec4 {
    float v[4];
    float &operator[](int i) { return v[i]; }
};

extern "C" Vec4 *func_00422240(Vec4 *out, Vec3 *in, float s, float w) {
    (*out)[0] = (*in)[0] * s;
    (*out)[1] = (*in)[1] * s;
    (*out)[2] = (*in)[2] * s;
    out->v[3] = w;
    return out;
}
