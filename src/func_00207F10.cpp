typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32, s32);
};

struct Obj00207F10 {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_00207F10(struct Obj00207F10 *arg0, s32 arg1, s32 arg2) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x328);

    e->fn((char *)arg0 + e->delta, arg1, arg2, 0);
}
