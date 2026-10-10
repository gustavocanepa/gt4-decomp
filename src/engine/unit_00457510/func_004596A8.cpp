typedef float f32;

struct Vec3 { f32 x, y, z; char pad[4]; };
struct VEntry { short delta; short index; void (*fn)(Vec3 *, void *); };
struct Obj { VEntry *vtbl; };
extern "C" void func_004A79B0(f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79D8(f32);

extern "C" void func_004596A8(Obj *o) {
    Vec3 v;
    VEntry *e = o->vtbl + 7;
    e->fn(&v, (char *)o + e->delta);
    func_004A79B0(v.y);
    func_004A7988(v.x);
    func_004A79D8(v.z);
}
