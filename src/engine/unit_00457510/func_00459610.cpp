typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

struct VEntry {
    short delta;
    short index;
    Vec3 (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void func_004A79B0(f32 a);
extern "C" void func_004A7988(f32 a);
extern "C" void func_004A79D8(f32 a);

extern "C" void func_00459610(Obj *o) {
    VEntry *e = &o->vtbl[4];
    Vec3 r = e->fn((char *)o + e->delta);
    func_004A79B0(r.y);
    func_004A7988(r.x);
    func_004A79D8(r.z);
}
