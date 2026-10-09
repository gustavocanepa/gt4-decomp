typedef short s16;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" f32 func_0038CD38(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x140);

    return -e->fn((char *)arg0 + e->delta);
}
