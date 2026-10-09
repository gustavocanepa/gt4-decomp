typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    VEntry *vtbl;
};

struct Obj {
    char pad0[0xC44];
    Sub *unkC44;
};

extern "C" void DevelopCamera__virtual_15(Obj *arg0) {
    Sub *s = arg0->unkC44;
    VEntry *e = (VEntry *)((char *)s->vtbl + 0x80);

    e->fn((char *)s + e->delta);
}
