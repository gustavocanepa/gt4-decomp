struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Stream {
    int f0;
    VEntry *vtbl;
};

extern "C" void func_005779E8(Stream *s);
extern "C" void func_00577A08(Stream *s);

extern "C" void func_00577EA0(Stream *s) {
    func_005779E8(s);
    VEntry *e = &s->vtbl[4];
    e->fn((char *)s + e->delta);
    func_005779E8(s);
    func_00577A08(s);
}
