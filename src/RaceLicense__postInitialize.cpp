typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad68[0x24EE0 - 0x68];
    int m24EE0;
    int m24EE4;
};

extern "C" void func_00388880(Obj *o);
extern "C" void func_00372088(void *p, int a);

extern "C" void RaceLicense__postInitialize(Obj *o) {
    func_00388880(o);
    if (o->m24EE0 && !o->m24EE4) {
        VEntry *e = (VEntry *)(o->vtbl + 0xD0);
        func_00372088(e->fn((char *)o + e->delta, 0), 0);
    }
}
