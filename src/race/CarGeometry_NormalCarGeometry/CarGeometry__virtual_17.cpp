typedef short s16;

struct VEntry_0038E008 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner_0038E008 {
    VEntry_0038E008 *vtbl;
};

struct Obj_0038E008 {
    char pad[0x1C];
    Inner_0038E008 *unk1C;
};

extern "C" void CarGeometry__virtual_17(struct Obj_0038E008 *arg0) {
    Inner_0038E008 *a1 = arg0->unk1C;
    VEntry_0038E008 *e = (VEntry_0038E008 *)((char *)a1->vtbl + 0x90);

    e->fn((char *)a1 + e->delta);
}
