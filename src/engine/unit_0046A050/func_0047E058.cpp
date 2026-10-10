struct Vec4 {
    float x, y, z, w;
};

extern "C" void func_0047E058(Vec4 *out, const Vec4 *a, const Vec4 *b, float t) {
    float s = 1.0f - t;
    for (int i = 0; i < 4; i++) {
        const Vec4 &p = a[i];
        const Vec4 &q = b[i];
        out->x = p.x * s + q.x * t;
        out->y = p.y * s + q.y * t;
        out->z = p.z * s + q.z * t;
        out->w = p.w * s + q.w * t;
        out++;
    }
}
