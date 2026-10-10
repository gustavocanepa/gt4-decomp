typedef short s16;

struct Res {
    void *value;
    int level;
    int m8;
};

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *, int, int, int, Res *);
};

struct Obj {
    int m0;
    char *vtbl;
};

extern "C" int func_005BFBA8(Obj *o, int a, int b, void **out) {
    Res r;
    r.value = 0;
    r.level = 0;
    r.m8 = 0;
    VEntry *e = (VEntry *)(o->vtbl + 0x10);
    if (e->fn((char *)o + e->delta, 6, a, b, &r))
        return 0;
    *out = r.value;
    return r.level >= 6;
}
