extern "C" void func_004A53F8(void);
extern "C" void func_004A74A0(void);
extern "C" void func_00455528(void *p, int flag);
extern "C" void func_004A5400(void);
extern "C" void func_004A3230(int n);

struct Obj {
    void *a;
    void *b;
};

extern "C" void func_0044EA58(Obj *o)
{
    if (o->a) {
        func_004A53F8();
        func_004A74A0();
        func_00455528(o->a, 0);
        func_004A5400();
    }
    func_004A3230(2);
    if (o->b)
        func_00455528(o->b, 0);
}
