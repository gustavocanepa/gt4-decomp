extern "C" void func_001D6ED8(void *);
extern "C" void func_001D6E80(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Target {
    char pad0[0x3C];
    int value;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void MHttp__set_timeout(void *arg0, void *arg1, int count, void *name)
{
    A a;
    B b;
    func_001D6ED8(&a);
    Target *t = a.p;
    func_002FC8C8(&b, name);
    t->value = func_002FE250(get(&b));
    func_002FC870(&b, 2);
    func_001D6E80(&a, 2);
}
