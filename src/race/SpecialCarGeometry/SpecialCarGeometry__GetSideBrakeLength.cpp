typedef short s16;

struct VEntry_0038C5A0 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_0038C5A0 {
    VEntry_0038C5A0 *vtbl;
};

extern "C" void SpecialCarGeometry__GetSideBrakeLength(Obj_0038C5A0 *arg0) {
    VEntry_0038C5A0 *e = (VEntry_0038C5A0 *)((char *)arg0->vtbl + 0x100);

    e->fn((char *)arg0 + e->delta);
}
