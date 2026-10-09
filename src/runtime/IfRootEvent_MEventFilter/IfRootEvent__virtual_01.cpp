typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    s32 unk0;
    VEntry *vtbl;
};

struct Matcher {
    s32 unk0;
    s32 id;
    s32 kind;
    s32 found;
};

extern "C" s32 func_0025C1E8(s32);
extern "C" s32 func_0028EA18(Obj *);

extern "C" s32 IfRootEvent__virtual_01(Matcher *self, Obj **ref) {
    s32 ok = 0;
    s32 t = func_0028EA18(*ref);
    if (t != 0) {
        Obj *o = *ref;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x50);
        if (e->fn((char *)o + e->delta) == self->kind) {
            ok = func_0025C1E8(t) == self->id;
        }
    }
    if (ok != 0) {
        self->found = 1;
    }
    return ok;
}
