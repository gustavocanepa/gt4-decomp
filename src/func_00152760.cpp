extern "C" void func_002F7BC0(void *b, void *value);
extern "C" void func_002F7B68(void *b, int in_chrg);
extern "C" float func_002F9158(int v);
extern "C" void func_00151888(void *a, void *self);
extern "C" void func_00151830(void *a, int in_chrg);
extern "C" void func_00154300(void *obj, float v);

struct A {
    void *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline void *obj(A *a) { return a->p; }

extern "C" void func_00152760(void *arg0, void *self, void *arg2, void *value)
{
    B b;
    A a;
    func_002F7BC0(&b, value);
    func_00151888(&a, self);
    void *o = obj(&a);
    func_00154300(o, func_002F9158(b.v[0]));
    func_00151830(&a, 2);
    func_002F7B68(&b, 2);
}
