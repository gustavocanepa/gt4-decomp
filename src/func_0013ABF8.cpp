typedef short s16;

struct VEntry0013ABF8 {
    s16 delta;
    s16 index;
    int (*fn)(void *, int);
};

struct Sub0013ABF8 {
    char pad0[4];
    VEntry0013ABF8 *vtbl;
};

struct Obj0013ABF8 {
    char pad0[0x2A4];
    Sub0013ABF8 *unk2A4;
};

extern "C" void func_0013ABF8(struct Obj0013ABF8 *arg0, int arg1) {
    Sub0013ABF8 *a2 = arg0->unk2A4;

    if (a2 != 0) {
        VEntry0013ABF8 *e = (VEntry0013ABF8 *)((char *)a2->vtbl + 0x1A0);
        int (*fn)(void *, int) = e->fn;
        fn((char *)a2 + e->delta, arg1);
    }
}
