typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct Owner {
    char pad0[0x10140];
    VEntry *vtbl;
};

struct Obj {
    s32 unk0;
    Owner *owner;
};

extern "C" s32 func_003445F0(Obj *self) {
    Owner *o = self->owner;
    VEntry *e = o->vtbl + 34;
    return e->fn((char *)o + e->delta, self);
}
