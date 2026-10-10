typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
};

typedef void (*Fn0)(void *self);
typedef void (*Fn1)(void *self, int value);

extern "C" void RaceBase__createGhostInformation(Obj *self, int value) {
    VEntry *e = &self->vtbl[27];
    ((Fn0)e->fn)((char *)self + e->delta);
    VEntry *f = &self->vtbl[65];
    ((Fn1)f->fn)((char *)self + f->delta, value);
}
