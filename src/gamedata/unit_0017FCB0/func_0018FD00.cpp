struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int);
};

struct Target {
    char pad0[0xC];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x10];
    void *table;
};

extern "C" Target *func_00436F20(void *table, int a, int b);

extern "C" void func_0018FD00(Obj *o, int value, int a, int b) {
    Target *t = func_00436F20(o->table, a, b);
    VEntry *e = &t->vtbl[3];
    e->fn((char *)t + e->delta, value);
}
