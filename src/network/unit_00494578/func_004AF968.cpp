typedef short s16;
typedef int s32;
typedef long long s64;

struct VEntry {
    s16 delta;
    s16 index;
    s64 (*fn)(void *self, s32 a, s32 b, s32 c);
};

struct Manager {
    char pad0[0xA4];
    VEntry *vtbl;
};

extern "C" Manager *func_004AFA78(void);

extern "C" s32 func_004AF968(s32 a, s32 b, s32 c) {
    Manager *m = func_004AFA78();
    VEntry *e = &m->vtbl[21];
    return e->fn((char *)m + e->delta, a, b, c);
}
