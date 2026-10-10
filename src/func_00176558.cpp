extern "C" void func_00174148(void *);
extern "C" void func_001740F0(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002FE250(int);
extern "C" void func_001CC130(void *obj, bool on);

struct Owner {
    char pad0[0x10];
    void *target;
};

struct A {
    Owner *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00176558(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00174148(&a);
        func_002FC8C8(&b, name);
        func_001CC130(a.p->target, func_002FE250(get(&b)) != 0);
        func_002FC870(&b, 2);
        func_001740F0(&a, 2);
    }
}
