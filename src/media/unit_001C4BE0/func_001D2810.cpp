typedef short s16;
typedef int s32;

struct VEntry_001D2810 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj_001D2810 {
    VEntry_001D2810 *vtbl;
};

struct Outer_001D2810 {
    char pad[0x30];
    Obj_001D2810 *unk30;
};

static inline s32 vcall_001D2810(struct Obj_001D2810 *o) {
    VEntry_001D2810 *e = (VEntry_001D2810 *)((char *)o->vtbl + 0x30);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_001D2810(struct Outer_001D2810 *arg0) {
    vcall_001D2810(arg0->unk30);
}
