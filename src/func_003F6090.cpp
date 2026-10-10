typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    char pad[0x10140];
    char *vtbl;
};

extern "C" s32 func_003F6090(Obj *self) {
    VEntry *e = (VEntry *)(self->vtbl + 0x120);
    return e->fn((char *)self + e->delta, 0) == 0;
}
