typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct VObj {
    char pad[0xD0];
    char *vtbl;
};

struct Obj {
    char pad[0xC];
    VObj *owner;
};

extern "C" s32 func_00353EB8(Obj *);

extern "C" void func_00354A78(Obj *self) {
    s32 v = func_00353EB8(self);
    VObj *o = self->owner;
    VEntry *e = (VEntry *)(o->vtbl + 0x30);
    e->fn((char *)o + e->delta, v);
}
