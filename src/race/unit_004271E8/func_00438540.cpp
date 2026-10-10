typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    char pad[4];
    s32 unk4;
    char pad8[4];
    char *vtbl;
};

extern "C" s32 func_00438340(s32);

extern "C" s32 func_00438540(Obj *self) {
    s32 v = func_00438340(self->unk4);
    VEntry *e = (VEntry *)(self->vtbl + 0x40);
    return e->fn((char *)self + e->delta, v);
}
