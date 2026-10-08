typedef short s16;

struct VEntry003A01F0 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Sub003A01F0 {
    char pad0[0x14];
    VEntry003A01F0 *vtbl;
};

struct Obj003A01F0 {
    char pad0[0x14];
    Sub003A01F0 *unk14;
};

extern "C" void func_003A01F0(struct Obj003A01F0 *arg0) {
    Sub003A01F0 *a1 = arg0->unk14;

    if (a1 != 0) {
        VEntry003A01F0 *e = (VEntry003A01F0 *)((char *)a1->vtbl + 0x58);
        e->fn((char *)a1 + e->delta);
    }
}
