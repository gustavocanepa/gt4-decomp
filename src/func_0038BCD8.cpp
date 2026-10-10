typedef float f32;

struct VEntry {
    short delta;
    short index;
    f32 (*fn)(void *);
};

struct Child {
    VEntry *vtbl;
};

struct Obj {
    char pad0[0xE420];
    Child *child;
};

extern "C" f32 func_0038BCD8(Obj *o) {
    Child *c = o->child;
    if (c) {
        VEntry *e = &c->vtbl[16];
        return e->fn((char *)c + e->delta);
    }
    return 1.0f;
}
