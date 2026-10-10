typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Child {
    char pad[0x20];
    char *vtbl;
};

struct Obj {
    char pad[0x60];
    Child *child;
    char pad64[0xE0 - 0x64];
    s32 value;
};

extern "C" void func_003BFCB0(Obj *self, s32 v) {
    Child *c = self->child;
    VEntry *e = (VEntry *)(c->vtbl + 0x30);
    e->fn((char *)c + e->delta, v);
    self->value = v;
}
