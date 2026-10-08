typedef short s16;

struct VEntry_0038C6D0 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj_0038C6D0 {
    VEntry_0038C6D0 *vtbl;
};

extern "C" void func_0038C6D0(Obj_0038C6D0 *arg0) {
    VEntry_0038C6D0 *e = (VEntry_0038C6D0 *)((char *)arg0->vtbl + 0x120);

    e->fn((char *)arg0 + e->delta);
}
