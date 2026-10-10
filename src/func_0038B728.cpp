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

extern "C" void func_0033CD78(Obj *);

extern "C" void func_0038B728(Obj *self) {
    func_0033CD78(self);
    Child *c = self->child;
    if (c != 0) {
        VEntry *e = (VEntry *)(c->vtbl + 0x20);
        e->fn((char *)c + e->delta);
    }
}
