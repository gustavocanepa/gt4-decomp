typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, void *);
};

struct Stage {
    char pad0[0x20];
    char *vtbl;
};

struct Obj;
extern "C" Stage *func_0041A8C0(Obj *o, int i);

extern "C" void *func_0041B358(Obj *o, void *p) {
    for (int i = 0; i < 20; i++) {
        Stage *s = func_0041A8C0(o, i);
        VEntry *e = (VEntry *)(s->vtbl + 0x40);
        p = e->fn((char *)s + e->delta, p);
    }
    return p;
}
