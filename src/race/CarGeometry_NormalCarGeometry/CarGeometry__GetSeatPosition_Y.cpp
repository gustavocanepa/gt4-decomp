typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0x1C];
    ObjInner *unk1C;
};

extern "C" void CarGeometry__GetSeatPosition_Y(Obj *arg0) {
    ObjInner *a1 = arg0->unk1C;
    VEntry *e = (VEntry *)((char *)a1->vtbl + 0x18);

    e->fn((char *)a1 + e->delta);
}
