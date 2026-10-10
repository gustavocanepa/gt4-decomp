typedef short s16;

struct VEntry_0020E640 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Inner_0020E640 {
    char pad0[0x0];
    VEntry_0020E640 *vtbl;
};

struct Obj_0020E640 {
    char pad[0x1C];
    Inner_0020E640 *unk8;
};

extern "C" void CarGeometry__GetFixedRightHandlePosition_Y(struct Obj_0020E640 *arg0) {
    Inner_0020E640 *a1 = arg0->unk8;
    VEntry_0020E640 *e = (VEntry_0020E640 *)((char *)a1->vtbl + 0x130);

    e->fn((char *)a1 + e->delta);
}
