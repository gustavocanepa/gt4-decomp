typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub {
    char pad0[0x0];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x4];
    Sub *unk58;
};

extern "C" void func_005D12E8(struct Obj *arg0) {
    Sub *a1 = arg0->unk58;

    if (a1 != 0) {
        VEntry *e = (VEntry *)((char *)a1->vtbl + 0x10);
        e->fn((char *)a1 + e->delta);
    }
}
