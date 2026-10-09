typedef short s16;
typedef int s32;

struct VEntry0037BDF8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *);
};

struct ObjInner0037BDF8 {
    char pad0[8];
    VEntry0037BDF8 *vtbl;
};

struct Result0037BDF8 {
    char pad0[0x40];
    s32 unk40;
};

struct Mid0037BDF8 {
    char pad0[0x2880];
    ObjInner0037BDF8 *unk2880;
};

struct Obj0037BDF8 {
    char pad0[0x18C];
    Mid0037BDF8 *unk18C;
};

extern "C" s32 func_0037BDF8(struct Obj0037BDF8 *arg0) {
    ObjInner0037BDF8 *a1 = arg0->unk18C->unk2880;
    VEntry0037BDF8 *e = (VEntry0037BDF8 *)((char *)a1->vtbl + 0x50);
    struct Result0037BDF8 *r = (struct Result0037BDF8 *)e->fn((char *)a1 + e->delta);

    return r->unk40;
}
