extern "C" void func_0020B398(void *);
extern "C" void func_0020B340(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Target {
    char pad0[0x38];
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

extern "C" void func_0020BAC8(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_0020B398(&a);
        func_002FC8C8(&b, name);
        int v = func_002FE250(get(&b)) != 0;
        Target *t = a.p;
        t->value = v;
        func_002FC870(&b, 2);
        func_0020B340(&a, 2);
    }
}
