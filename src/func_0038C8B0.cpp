typedef short s16;

struct VEntry_00109910 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_00109910 {
    char pad[0x0];
    VEntry_00109910 *vtbl;
};

extern "C" void func_0038C8B0(Obj_00109910 *arg0) {
    VEntry_00109910 *e = (VEntry_00109910 *)((char *)arg0->vtbl + 0x10);

    e->fn((char *)arg0 + e->delta);
}
