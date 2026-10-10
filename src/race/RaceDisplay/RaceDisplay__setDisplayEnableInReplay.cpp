typedef short s16;
typedef int s32;

struct VEntry_003A2008 {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj_003A2008 {
    VEntry_003A2008 *vtbl;
};

extern "C" void RaceDisplay__setDisplayEnableInReplay(struct Obj_003A2008 *arg0, s32 arg1) {
    VEntry_003A2008 *e = (VEntry_003A2008 *)((char *)arg0->vtbl + 0x1C0);

    e->fn((char *)arg0 + e->delta, arg1 != 0);
}
