typedef int s32;

struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { void *f0; char pad4[0x30]; s32 f34; VEntry *vtbl; };
extern "C" void func_00578480(void *);

static inline void vcall2(Obj *o) {
    VEntry *e = o->vtbl + 2;
    e->fn((char *)o + e->delta);
}

extern "C" void func_005780F8(Obj *o) {
    vcall2(o);
    if (o->f34)
        func_00578480(o->f0);
}
