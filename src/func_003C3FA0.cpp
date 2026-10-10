typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
};

extern "C" Obj *func_003C3F98(void);

extern "C" s32 func_003C3FA0(void) {
    Obj *o = func_003C3F98();
    VEntry *e = o->vtbl + 26;
    return e->fn((char *)o + e->delta, 0);
}
