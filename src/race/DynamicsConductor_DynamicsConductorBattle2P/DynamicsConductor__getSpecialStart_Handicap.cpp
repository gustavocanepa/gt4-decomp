typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *, int);
};

struct Obj {
    char pad0[0x10140];
    char *vtbl;
};

extern "C" int DynamicsConductor__GetStartVOffsetBySectionSet(Obj *o);

extern "C" int DynamicsConductor__getSpecialStart_Handicap(Obj *o, int arg, int *found, int *size) {
    VEntry *e = (VEntry *)(o->vtbl + 0x118);
    int n = e->fn((char *)o + e->delta, arg);
    if (n == 0)
        return 0;
    *found = 1;
    *size = n;
    *size += DynamicsConductor__GetStartVOffsetBySectionSet(o);
    return 1;
}
