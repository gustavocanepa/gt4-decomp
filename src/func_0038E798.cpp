typedef short s16;

typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct ObjInner {
    VEntry *vtbl;
};

struct Obj {
    char pad[0x1C];
    ObjInner *unk30;
};

extern "C" void func_0038E798(Obj *arg0) {
    ObjInner *a1 = arg0->unk30;
    VEntry *e = (VEntry *)((char *)a1->vtbl + 0x180);

    e->fn((char *)a1 + e->delta);
}
