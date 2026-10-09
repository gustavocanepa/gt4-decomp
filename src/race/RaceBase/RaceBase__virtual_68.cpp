typedef short s16;
typedef int s32;

struct VEntry_00338CD8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj_00338CD8 {
    char pad0[0x64];
    VEntry_00338CD8 *unk64;
};

static inline s32 vcall(Obj_00338CD8 *o) {
    VEntry_00338CD8 *e = (VEntry_00338CD8 *)((char *)o->unk64 + 0x230);
    return e->fn((char *)o + e->delta);
}

extern "C" void RaceBase__virtual_68(Obj_00338CD8 *arg0) {
    vcall(arg0);
}
