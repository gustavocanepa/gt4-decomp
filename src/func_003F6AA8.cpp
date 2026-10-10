typedef short s16;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *self);
};

struct Obj {
    char pad0[0x10140];
    VEntry *vtbl;
};

extern f32 D_00622490[];

extern "C" f32 func_003F6AA8(Obj *self) {
    f32 *table = D_00622490;
    VEntry *e = &self->vtbl[42];
    int i = e->fn((char *)self + e->delta);
    return table[i - 1];
}
