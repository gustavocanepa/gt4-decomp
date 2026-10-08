typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32);
};

struct Obj2 {
    char pad0[4];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x10];
    struct Obj2 *unk10;
    s32 unk14;
};

extern "C" void func_002F1118(struct Obj *arg0, s32 arg1) {
    struct Obj2 *self2 = arg0->unk10;
    s32 val = arg0->unk14;
    VEntry *e = (VEntry *)((char *)self2->vtbl + 0x78);

    e->fn((char *)self2 + e->delta, val, arg1);
}
