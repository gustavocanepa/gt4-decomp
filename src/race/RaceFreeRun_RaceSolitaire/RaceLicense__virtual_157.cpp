typedef short s16;

struct VEntry_003EB340 {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Obj_003EB340 {
    char pad0[0x64];
    VEntry_003EB340 *vtbl;
};

extern "C" void RaceLicense__virtual_157(struct Obj_003EB340 *arg0, void *arg1) {
    VEntry_003EB340 *e = (VEntry_003EB340 *)((char *)arg0->vtbl + 0x1C8);

    e->fn((char *)arg0 + e->delta, arg1);
}
