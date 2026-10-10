typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj {
    VEntry *vtbl;
};

struct Owner {
    VEntry *vtbl;
    s32 unk4;
};

typedef Obj *(*GetFn)(void *self, s32 arg);
typedef void (*SetFn)(void *self, s32 arg);

extern "C" void RaceSplitDisplayBase__setTargetCarNumber(Owner *self, s32 value) {
    VEntry *e = &self->vtbl[25];
    Obj *obj = ((GetFn)e->fn)((char *)self + e->delta, self->unk4);
    VEntry *f = &obj->vtbl[11];
    ((SetFn)f->fn)((char *)obj + f->delta, value);
}
