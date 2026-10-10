typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *);
};

struct Dev {
    char *vtbl;
};

struct Obj {
    char pad0[0x30];
    Dev *dev;
};

extern int D_00618D78;

static inline int vcall(Dev *d, int off)
{
    VEntry *e = (VEntry *)(d->vtbl + off);
    return e->fn((char *)d + e->delta);
}

extern "C" int func_001D28A0(Obj *o) {
    int r = vcall(o->dev, 0x10);
    if (vcall(o->dev, 0x40))
        D_00618D78 = (D_00618D78 != 0) | (r != 0);
    return r;
}
