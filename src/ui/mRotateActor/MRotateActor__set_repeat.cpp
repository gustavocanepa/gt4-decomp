extern "C" void func_002CC920(void *);
extern "C" void func_002CC8C8(void *, int);
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

extern "C" void MRotateActor__set_repeat(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_002CC920(&a);
        func_002FC8C8(&b, name);
        Target *t = a.p;
        t->value = func_002FE250(get(&b)) != 0;
        func_002FC870(&b, 2);
        func_002CC8C8(&a, 2);
    }
}
