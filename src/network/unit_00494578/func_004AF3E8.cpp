typedef int s32;

struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0xA8]; VEntry *vtbl; };

static inline void vcall(Obj *o, int slot) {
    VEntry *e = o->vtbl + slot;
    e->fn((char *)o + e->delta);
}

extern "C" void func_004AF3E8(Obj *o) {
    vcall(o, 2);
    vcall(o, 4);
}
