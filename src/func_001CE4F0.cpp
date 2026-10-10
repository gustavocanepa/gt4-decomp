struct Name { char s[0x50]; };

struct Res {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int state();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual int find(Name *name, int arg, int size, int flags);
};

extern "C" void func_001CE460(void *src, Name *name);

extern "C" int func_001CE4F0(void *src, Res *res, int arg) {
    Name name;
    func_001CE460(src, &name);
    res->find(&name, arg, 0x40, 0);
    int r = res->state();
    switch (r) {
    case 0:
        return 0;
    case 2:
        return 2;
    }
    return 1;
}
