extern "C" void func_0015D898(void *);
extern "C" void func_0015D840(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Target {
    char pad0[0x60];
    int value;
};

struct Owner {
    char pad0[0x10];
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

extern "C" void func_0015E418(void *arg0, void *arg1, int count, void *name)
{
    A a;
    B b;
    func_0015D898(&a);
    Target *t = a.p->target;
    func_002FC8C8(&b, name);
    t->value = func_002FE250(get(&b)) != 0;
    func_002FC870(&b, 2);
    func_0015D840(&a, 2);
}
