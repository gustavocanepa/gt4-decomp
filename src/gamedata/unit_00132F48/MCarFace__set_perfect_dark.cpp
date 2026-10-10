extern "C" void func_00137DB8(void *);
extern "C" void func_00137D60(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);

struct Value {
    int v;
    void set(int x) { v = x; }
};

struct Target {
    char pad0[0x138];
    Value value;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void MCarFace__set_perfect_dark(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00137DB8(&a);
        func_002FC8C8(&b, name);
        Target *t = a.p;
        t->value.set(func_002FE250(get(&b)) != 0);
        func_002FC870(&b, 2);
        func_00137D60(&a, 2);
    }
}
