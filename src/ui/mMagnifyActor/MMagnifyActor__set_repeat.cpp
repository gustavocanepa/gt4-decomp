extern "C" void func_002B9830(void *);
extern "C" void func_002B97D8(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Target {
    char pad0[0x2C];
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

extern "C" void MMagnifyActor__set_repeat(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_002B9830(&a);
        func_002FC8C8(&b, name);
        Target *t = a.p;
        t->value = func_002FE250(get(&b)) != 0;
        func_002FC870(&b, 2);
        func_002B97D8(&a, 2);
    }
}
