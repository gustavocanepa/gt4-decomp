typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj_0010AB78 {
    char pad0[0x64];
    VEntry *vtbl;
    char pad1[0xA0 - 0x64 - 4];
    s32 unkA0;
};

extern s32 D_00618498;

extern "C" void func_0010AB78(struct Obj_0010AB78 *arg0) {
    VEntry *e;

    arg0->unkA0 = 0;
    e = (VEntry *)((char *)arg0->vtbl + 0x90);
    e->fn((char *)arg0 + e->delta, D_00618498);
}
