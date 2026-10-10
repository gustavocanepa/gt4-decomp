/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x14];
    s32 busy;
    char pad18[0x50];
    VEntry *vtbl;
};

extern "C" void func_00565A30(Obj *self) {
    if (self->busy == 0) {
        VEntry *e = self->vtbl + 1;
        e->fn((char *)self + e->delta);
    }
}
