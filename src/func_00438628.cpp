typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 key;
    VEntry *vtbl;
};

extern "C" s32 func_00438340(s32 key);

extern "C" s32 func_00438628(Obj *self) {
    s32 v = func_00438340(self->key);
    VEntry *e = self->vtbl + 11;
    return e->fn((char *)self + e->delta, v);
}
