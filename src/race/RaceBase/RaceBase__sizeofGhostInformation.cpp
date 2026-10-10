typedef short s16;
typedef int s32;

struct VEntry_00389388 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj_00389388 {
    char pad0[0x64];
    VEntry_00389388 *vtbl;
};

extern "C" s32 RaceBase__sizeofGhostInformation(struct Obj_00389388 *arg0) {
    VEntry_00389388 *e = (VEntry_00389388 *)((char *)arg0->vtbl + 0x210);

    return e->fn((char *)arg0 + e->delta) + 0x1AA4;
}
