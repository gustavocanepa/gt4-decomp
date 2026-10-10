struct Vec3 {
    float x, y, z;
};

struct Vec4 {
    float x, y, z, w;
};

extern "C" void func_004A7AA8(void *, Vec4 *);

extern "C" void func_004515C0(void *self, Vec3 *p) {
    Vec4 v;
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    v.w = 1.0f;
    func_004A7AA8(self, &v);
}
