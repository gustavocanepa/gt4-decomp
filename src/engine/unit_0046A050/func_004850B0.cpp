typedef short s16;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, int, f32);
};

struct VObj {
    char pad[0x5C];
    char *vtbl;
};

struct Obj {
    char pad[0x74];
    VObj *child;
};

extern "C" void func_004850B0(Obj *self, int arg1) {
    VObj *o = self->child;
    if (o != 0) {
        VEntry *e = (VEntry *)(o->vtbl + 0x20);
        e->fn((char *)o + e->delta, arg1, 0.0f);
    }
}
