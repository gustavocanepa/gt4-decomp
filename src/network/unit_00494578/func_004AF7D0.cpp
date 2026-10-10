struct VEntry {
    short delta;
    short index;
    int (*fn)(void *, void *);
};

struct Obj {
    char pad0[0xA4];
    VEntry *vtbl;
};

extern "C" Obj *func_004AFA78(void *self);

extern "C" int func_004AF7D0(void *self) {
    Obj *o = func_004AFA78(self);
    VEntry *e = &o->vtbl[18];
    return e->fn((char *)o + e->delta, self);
}
