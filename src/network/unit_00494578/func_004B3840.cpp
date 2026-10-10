struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
    int a;
    int b;
    int fC;
    char sub[0x10];
};

extern "C" void func_004B3BD0(void *sub, int v);

extern "C" void func_004B3840(Obj *o, int a, int b) {
    o->a = a;
    o->b = b;
    VEntry *e = &o->vtbl[2];
    int v = e->fn((char *)o + e->delta);
    func_004B3BD0(o->sub, v);
}
