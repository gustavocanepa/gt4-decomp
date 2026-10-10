typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Owner {
    char pad0[0x5C];
    VEntry *vtbl;
};

struct Obj {
    Owner *owner;
    char pad4[0x20];
    s32 unk24;
    s32 unk28;
};

extern "C" void func_004756F8(Obj *self) {
    self->unk24 = 0;
    self->unk28 = 0;
    Owner *o = self->owner;
    VEntry *e = o->vtbl + 7;
    e->fn((char *)o + e->delta, self);
}
