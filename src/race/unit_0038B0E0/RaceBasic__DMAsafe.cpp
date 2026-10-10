typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Child {
    char *vtbl;
};

struct Obj {
    char pad[0xE420];
    Child *child;
};

extern "C" void RacePS2Base__DMAsafe(Obj *);

extern "C" void RaceBasic__DMAsafe(Obj *self) {
    RacePS2Base__DMAsafe(self);
    Child *c = self->child;
    if (c != 0) {
        VEntry *e = (VEntry *)(c->vtbl + 0x20);
        e->fn((char *)c + e->delta);
    }
}
