typedef short s16;

struct VEntry0013A9A8 {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

struct Sub0013A9A8 {
    char pad0[0x0];
    VEntry0013A9A8 *vtbl;
};

struct Obj0013A9A8 {
    char pad0[0x4];
    Sub0013A9A8 *unk2A4;
};

extern "C" void func_005604D0(struct Obj0013A9A8 *arg0, int arg1) {
    Sub0013A9A8 *a2 = arg0->unk2A4;

    if (a2 != 0) {
        VEntry0013A9A8 *e = (VEntry0013A9A8 *)((char *)a2->vtbl + 0x18);
        e->fn((char *)a2 + e->delta, arg1);
    }
}
