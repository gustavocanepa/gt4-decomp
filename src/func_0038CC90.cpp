typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void func_0038CC90(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x118);

    e->fn((char *)arg0 + e->delta);
}
