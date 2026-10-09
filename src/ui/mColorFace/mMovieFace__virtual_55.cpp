typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void mMovieFace__virtual_55(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x1C8);

    e->fn((char *)arg0 + e->delta, 0);
}
