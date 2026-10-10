typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
};

static inline void vcall(Obj *self, int slot) {
    VEntry *e = &self->vtbl[slot];
    e->fn((char *)self + e->delta);
}

extern "C" void func_001098A0(Obj *self) {
    vcall(self, 6);
    vcall(self, 5);
    vcall(self, 7);
}
