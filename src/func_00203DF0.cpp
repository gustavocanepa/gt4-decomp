extern "C" void func_00203678(void *);
extern "C" void func_00203620(void *, int);
extern "C" void func_002F7BC0(void *, void *);
extern "C" void func_002F7B68(void *, int);
extern "C" float func_002F9158(int);

struct Target {
    char pad0[0x18];
    float value;
};

struct A {
    Target *p;
    int pad[3];
};

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00203DF0(void *arg0, void *arg1, int count, void *name)
{
    A a;
    B b;
    func_00203678(&a);
    func_002F7BC0(&b, name);
    Target *t = a.p;
    t->value = func_002F9158(get(&b));
    func_002F7B68(&b, 2);
    func_00203620(&a, 2);
}
