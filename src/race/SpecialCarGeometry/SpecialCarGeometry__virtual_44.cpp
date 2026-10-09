typedef short s16;

struct VEntry_0038C7F8 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_0038C7F8 {
    VEntry_0038C7F8 *vtbl;
};

extern "C" void SpecialCarGeometry__virtual_44(Obj_0038C7F8 *arg0) {
    VEntry_0038C7F8 *e = (VEntry_0038C7F8 *)((char *)arg0->vtbl + 0x150);

    e->fn((char *)arg0 + e->delta);
}
