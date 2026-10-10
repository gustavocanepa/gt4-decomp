typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self, s32 a, s32 b);
};

struct Manager {
    char pad0[0xA4];
    VEntry *vtbl;
};

extern "C" Manager *func_004AFA78(void);

extern "C" s32 func_004AFA20(s32 a, s32 b) {
    Manager *m = func_004AFA78();
    VEntry *e = &m->vtbl[24];
    return e->fn((char *)m + e->delta, a, b);
}
