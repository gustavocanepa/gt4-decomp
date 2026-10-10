typedef short s16;
typedef int s32;

struct VObj;

struct VEntryB {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct VObj {
    VEntryB *vtbl;
};

struct VEntryA {
    s16 delta;
    s16 index;
    VObj *(*fn)(void *, s32);
};

struct Obj {
    VEntryA *vtbl;
    s32 arg;
};

extern "C" void RaceSplitDisplayBase__getBackMirrorRate(Obj *self) {
    VEntryA *e = self->vtbl + 26;
    VObj *o = e->fn((char *)self + e->delta, self->arg);
    VEntryB *f = o->vtbl + 16;
    f->fn((char *)o + f->delta);
}
