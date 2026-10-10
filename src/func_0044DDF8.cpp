struct Vec3 {
    float x, y, z;
};

struct Obj {
    char pad[8];
    float x;
    float y;
};

extern "C" void func_0044DCC0(Obj *, Vec3 *, Vec3 *);

extern "C" void func_0044DDF8(Obj *self, float x, float y, float z) {
    Vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    func_0044DCC0(self, &v, &v);
    self->x = v.x;
    self->y = v.y;
}
