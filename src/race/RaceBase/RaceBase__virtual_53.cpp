typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
};

extern "C" s32 RaceBase__virtual_53(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x1D8);

    return e->fn((char *)arg0 + e->delta) + 0x1AA4;
}
