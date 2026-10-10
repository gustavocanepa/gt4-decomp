typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32);
};

struct Child {
    VEntry *vtbl;
};

struct Obj {
    char pad0[0xE420];
    Child *child;
};

extern "C" void func_0038BC98(Obj *self, s32 a, s32 b) {
    Child *c = self->child;
    if (c) {
        VEntry *e = c->vtbl + 19;
        e->fn((char *)c + e->delta, a, b);
    }
}
