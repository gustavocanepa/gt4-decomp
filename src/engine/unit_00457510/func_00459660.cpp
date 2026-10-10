typedef short s16;

struct Vec3 {
    float x, y, z;
};

struct VEntry {
    s16 delta;
    s16 index;
    Vec3 (*fn)(void *);
};

struct Obj {
    char *vtbl;
};

extern "C" void func_004A7844(float, float, float);

extern "C" void func_00459660(Obj *self) {
    VEntry *e = (VEntry *)(self->vtbl + 0x40);
    Vec3 v = e->fn((char *)self + e->delta);
    func_004A7844(v.x, v.y, v.z);
}
