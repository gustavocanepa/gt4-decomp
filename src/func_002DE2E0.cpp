extern "C" void func_002DD698(void *);
extern "C" void func_002DD640(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Target {
    char pad0[0xE4];
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

extern "C" void func_002DE2E0(void *arg0, void *arg1, int count, void *name)
{
    A a;
    B b;
    func_002DD698(&a);
    Target *t = a.p;
    func_002FC8C8(&b, name);
    t->value = func_002FE250(get(&b));
    func_002FC870(&b, 2);
    func_002DD640(&a, 2);
}
