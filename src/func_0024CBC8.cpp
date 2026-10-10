extern "C" void func_0024C860(void *h);
extern "C" void func_0024C808(void *h, int in_chrg);
extern "C" void func_0022AD20(void *s, void *name);
extern "C" void func_0022ACC8(void *s, int in_chrg);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int);
};

struct Target {
    int pad0;
    VEntry *vt;
};

struct Handle {
    Target *p;
    int pad[3];
};

struct Str {
    int v[4];
};

static inline int first(Str *s) { return s->v[0]; }

extern "C" void func_0024CBC8(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        Handle h;
        Str s;
        func_0024C860(&h);
        func_0022AD20(&s, name);
        Target *t = h.p;
        VEntry *e = &t->vt[54];
        e->fn((char *)t + e->delta, first(&s));
        func_0022ACC8(&s, 2);
        func_0024C808(&h, 2);
    }
}
