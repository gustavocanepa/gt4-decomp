typedef short s16;

struct VEntry_002638E8 {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Obj_002638E8 {
    char pad[4];
    VEntry_002638E8 *vtbl;
};

extern "C" void mSceneViewFace__virtual_85(Obj_002638E8 *arg0, void *arg1) {
    VEntry_002638E8 *e = (VEntry_002638E8 *)((char *)arg0->vtbl + 0x200);

    e->fn((char *)arg0 + e->delta, arg1);
}
