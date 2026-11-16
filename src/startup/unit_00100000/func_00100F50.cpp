/* dynamic_cast<D &>(*o).method(): func_005C0F40 (__dynamic_cast_2) with the type_info functions
   func_005C1F98 / func_005C24C8, bad_cast (exception__structor_2) when it fails, then the virtual call
   at slot 0x68 of the result. Written out by hand like func_002F67E8. */
struct VEntry {
    short delta;
    short index;
    void *fn;
};

struct Obj {
    char pad[0x64];
    VEntry *vtbl;
};

extern "C" char func_005C1F98[];
extern "C" char func_005C24C8[];
extern "C" Obj *__dynamic_cast_2(void *tf, void *target, int boff, void *top, void *src, Obj *o);
extern "C" void exception__structor_2(void) __attribute__((noreturn));

extern "C" void func_00100F50(Obj *o) {
    VEntry *e = o->vtbl;
    Obj *d = __dynamic_cast_2(e->fn, func_005C1F98, 0, (char *)o + e->delta, func_005C24C8, o);
    if (d == 0)
        exception__structor_2();
    VEntry *v = &d->vtbl[13];
    ((void (*)(void *))v->fn)((char *)d + v->delta);
}
