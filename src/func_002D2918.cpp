extern "C" void func_002D2598(void *);
extern "C" void func_002D2540(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_002D2CB8(void *obj, int value);

struct A {
    void *p;
    int pad[7];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_002D2918(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_002D2598(&a);
        void *obj = a.p;
        func_00255110(&b, name);
        func_002D2CB8(obj, get(&b));
        func_002550B8(&b, 2);
        func_002D2540(&a, 2);
    }
}
