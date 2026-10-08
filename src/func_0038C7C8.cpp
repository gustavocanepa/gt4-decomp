typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void func_0038C7C8(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x148);

    e->fn((char *)arg0 + e->delta);
}
