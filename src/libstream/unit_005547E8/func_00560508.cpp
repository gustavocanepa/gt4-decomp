typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VObj {
    char *vtbl;
};

struct Obj {
    void *m0;
    VObj *child;
};

extern "C" void func_0055F610(Obj *);

static inline s32 vcall(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x20);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_00560508(Obj *self) {
    VObj *o = self->child;
    if (o != 0) {
        vcall(o);
        return;
    }
    return func_0055F610(self);
}
