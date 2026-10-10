typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct VObj {
    char pad[0xAC];
    char *vtbl;
};

struct Obj {
    char pad[0x70];
    VObj *child;
};

extern "C" void func_003BFD90(Obj *self) {
    VObj *o = self->child;
    if (o != 0) {
        VEntry *e = (VEntry *)(o->vtbl + 8);
        e->fn((char *)o + e->delta, 3);
    }
    self->child = 0;
}
