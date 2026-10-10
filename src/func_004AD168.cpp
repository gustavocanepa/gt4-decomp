/* dynamic_cast<T *>(self->obj) written out as gcc 2.96's __dynamic_cast call (func_005C0FC8),
   as in func_002F67E8: the type-info functions are func_0060B0C8 (target) and func_0060B088 (source). */
struct VEntry {
    short delta;
    short pad2;
    void *tf;
};

struct Base {
    char pad0[0x20];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x4C];
    Base *obj;
};

extern "C" void func_0060B0C8(void);
extern "C" void func_0060B088(void);
extern "C" void *func_005C0FC8(void *tf, void (*target)(void), int require_public, void *address,
                               void (*source)(void), void *subptr);
extern "C" void func_004AFD50(void *p);

extern "C" void func_004AD168(Obj *self) {
    void *p = 0;
    Base *b = self->obj;
    if (b) {
        VEntry *e = b->vtbl;
        p = func_005C0FC8(e->tf, func_0060B0C8, 0, (char *)b + e->delta, func_0060B088, b);
    }
    if (p)
        func_004AFD50(p);
}
