typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct Target {
    char pad[0xA4];
    char *vtbl;
};

extern "C" Target *func_004AFA78(void *);

extern "C" s32 func_004AF9D8(void *self) {
    Target *t = func_004AFA78(self);
    VEntry *e = (VEntry *)(t->vtbl + 0xB0);
    return e->fn((char *)t + e->delta, self);
}
