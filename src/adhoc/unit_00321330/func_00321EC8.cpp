struct Tmp {
    int pad[4];
    Tmp() __asm__("func_0030BB18");
    ~Tmp() __asm__("func_00309378");
};

struct Target;

struct VEntry {
    short delta;
    short pad;
    void (*fn)(Target *self, int a, Tmp *t);
};

struct Target {
    int x;
    VEntry *vtbl;
};

struct Handle {
    Target *p;
    int pad[3];
    Handle() __asm__("func_00323D08");
    ~Handle() __asm__("func_00323B60");
};

extern "C" void func_00321E38(void *self, Handle *h, int key);

extern "C" void func_00321EC8(void *self, int a, int key)
{
    Handle h;
    func_00321E38(self, &h, key);
    if (h.p != 0) {
        VEntry *e = &h.p->vtbl[9];
        Target *t = (Target *)((char *)h.p + e->delta);
        Tmp tmp;
        e->fn(t, a, &tmp);
    }
}
