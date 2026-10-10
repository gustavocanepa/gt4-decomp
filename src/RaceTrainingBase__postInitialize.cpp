typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    char *vtbl;
    char pad68[0x125F8 - 0x68];
    int m125F8;
    int m125FC;
};

extern "C" void func_00388880(Obj *o);
extern "C" void func_00372088(void *p, int a);

extern "C" void RaceTrainingBase__postInitialize(Obj *o) {
    func_00388880(o);
    if (o->m125F8 && !o->m125FC) {
        VEntry *e = (VEntry *)(o->vtbl + 0xD0);
        func_00372088(e->fn((char *)o + e->delta, 0), 0);
    }
}
