extern "C" void * func_0015F3E0(void *);
extern "C" void func_0015F388(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Sub {
    char pad0[0x48];
    int value;
};
struct Owner {
    char pad0[0x10];
    char *q;
};
struct A {
    Owner *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00160850(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_0015F3E0(&a);
        func_002FC8C8(&b, name);
        Sub *t = (Sub *)(a.p->q + 0xD8);
        t->value = func_002FE250(get(&b));
        func_002FC870(&b, 2);
        func_0015F388(&a, 2);
    }
}
