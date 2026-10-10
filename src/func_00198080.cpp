extern "C" void func_001978D0(void *);
extern "C" void func_00197878(void *, int);
extern "C" void func_0019AA10(int, int);
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_0022ACC8(void *, int);

struct B {
    int v[4];
};

static inline int get(B *b) { return b->v[0]; }

extern "C" void func_00198080(void *arg0, void *arg1, void *arg2, void *arg3)
{
    int a[8];
    B b;
    int x;

    func_001978D0(a);
    x = a[0];
    func_0022AD20(&b, arg3);
    func_0019AA10(x, get(&b));
    func_0022ACC8(&b, 2);
    func_00197878(a, 2);
}
