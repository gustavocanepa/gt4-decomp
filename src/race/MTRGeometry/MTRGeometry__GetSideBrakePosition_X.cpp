typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void MTRGeometry__GetSideBrakePosition_X(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x90);

    e->fn((char *)arg0 + e->delta);
}
