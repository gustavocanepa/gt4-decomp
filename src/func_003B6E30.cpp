typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x1C];
    s32 cached;
    VEntry *vtbl;
};

extern "C" void func_003B6E30(Obj *self) {
    if (self->cached == 0) {
        VEntry *e = self->vtbl + 2;
        self->cached = e->fn((char *)self + e->delta);
    }
}
