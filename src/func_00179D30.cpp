extern "C" void func_001792D8(void *);
extern "C" void func_00179280(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Target {
    char pad0[0x688];
    int value;
};

struct Owner {
    char pad0[0x20];
    Target *target;
};

struct A {
    Owner *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00179D30(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_001792D8(&a);
        Target *t = a.p->target;
        func_002FC8C8(&b, name);
        t->value = func_002FE250(get(&b));
        func_002FC870(&b, 2);
        func_00179280(&a, 2);
    }
}
