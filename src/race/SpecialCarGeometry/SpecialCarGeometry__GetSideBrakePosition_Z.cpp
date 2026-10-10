typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void SpecialCarGeometry__GetSideBrakePosition_Z(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0xA0);

    e->fn((char *)arg0 + e->delta);
}
