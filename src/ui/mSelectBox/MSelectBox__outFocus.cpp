extern "C" void func_002D8B08(void *);
extern "C" void func_002D8AB0(void *, int);
extern "C" void func_00232C78(void *, void *);
extern "C" void func_00232C20(void *, int);
extern "C" void func_002DB3A8(void *obj, int value);

struct A {
    void *p;
    int pad[7];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void MSelectBox__outFocus(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_002D8B08(&a);
        void *obj = a.p;
        func_00232C78(&b, name);
        func_002DB3A8(obj, get(&b));
        func_00232C20(&b, 2);
        func_002D8AB0(&a, 2);
    }
}
