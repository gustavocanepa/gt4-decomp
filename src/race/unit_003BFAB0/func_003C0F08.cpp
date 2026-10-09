typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, int, int);
};

struct Sub {
    char pad0[0x64];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x84];
    Sub *unk84;
};

extern "C" void func_003C0F08(struct Obj *arg0, int arg1, int arg2) {
    Sub *a3 = arg0->unk84;

    if (a3 != 0) {
        VEntry *e = (VEntry *)((char *)a3->vtbl + 0x2A8);
        e->fn((char *)a3 + e->delta, arg1, arg2);
    }
}
