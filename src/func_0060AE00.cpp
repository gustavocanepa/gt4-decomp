/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32, s32);
};

struct Owner {
    char pad0[0xA4];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x38];
    Owner *owner;
};

extern "C" s32 func_0060AE00(Obj *self, s32 a, s32 b) {
    Owner *o = self->owner;
    VEntry *e = o->vtbl + 16;
    return e->fn((char *)o + e->delta, self, a, b);
}
