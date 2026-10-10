typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *, s32);
};

struct Listener {
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x6D4];
    Listener *listener;
};

extern "C" void func_002318C0(Obj *self, s32 arg) {
    Listener *l = self->listener;
    if (l) {
        VEntry *e = l->vtbl + 2;
        e->fn((char *)l + e->delta, self, arg);
    }
}
