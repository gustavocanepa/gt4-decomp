struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int, int, int, int);
};
struct Obj {
    char pad0[0x10140];
    char *vtbl;
};
extern "C" int DynamicsConductor__getSpecialStart_Rolling_ByCourse(Obj *o);

extern "C" void DynamicsConductorFreeRun__getSpecialStart(Obj *o, int a, int b, int c, int d) {
    if (!DynamicsConductor__getSpecialStart_Rolling_ByCourse(o)) {
        VEntry *e = (VEntry *)(o->vtbl + 0xF8);
        e->fn((char *)o + e->delta, a, b, c, d);
    }
}
