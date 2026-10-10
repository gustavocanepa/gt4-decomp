struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x30];
    void (*handler)(Obj *);
    int handlerArg;
    char pad38[0xA8 - 0x38];
    VEntry *vtbl;
};

extern "C" void func_004AC640(Obj *o);

extern "C" void func_004AC5D0(Obj *o) {
    VEntry *e = &o->vtbl[6];
    e->fn((char *)o + e->delta);
    o->handler = func_004AC640;
    o->handlerArg = 0;
}
