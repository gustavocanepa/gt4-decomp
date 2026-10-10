typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x64];
    char *vtbl;
};

extern "C" void RaceBase__cleanup(Obj *self) {
    VEntry *e1 = (VEntry *)(self->vtbl + 0x2D0);
    e1->fn((char *)self + e1->delta);
    VEntry *e2 = (VEntry *)(self->vtbl + 0x190);
    e2->fn((char *)self + e2->delta);
}
