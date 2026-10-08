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
    char pad[0xC44];
    ObjInner *unkC44;
};

extern "C" void func_003C8E10(Obj *arg0) {
    ObjInner *a1 = arg0->unkC44;
    VEntry *e = (VEntry *)((char *)a1->vtbl + 0x60);

    e->fn((char *)a1 + e->delta);
}
