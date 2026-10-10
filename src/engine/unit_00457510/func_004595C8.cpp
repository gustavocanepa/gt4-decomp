typedef short s16;
typedef float f32;

struct V3 { f32 x, y, z; f32 pad; };
struct VEntry { s16 delta; s16 index; void (*fn)(V3 *, void *); };
struct Obj { VEntry *vtbl; };
extern "C" void func_004A7844(f32, f32, f32);

extern "C" void func_004595C8(Obj *o) {
    V3 v;
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x28);
    e->fn(&v, (char *)o + e->delta);
    func_004A7844(v.x, v.y, v.z);
}
