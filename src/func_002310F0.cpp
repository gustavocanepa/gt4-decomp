extern "C" void func_003285A8(void *obj);
extern "C" void func_003285F8(void *obj);

struct Ref {
    void *p;
    int pad[3];
    void assign(const Ref &o)
    {
        if (this != &o) {
            void *np = o.p;
            if (np)
                func_003285A8(np);
            if (p)
                func_003285F8(p);
            p = np;
        }
    }
};

struct Obj {
    char pad0[0x6D8];
    Ref ref;
};

extern "C" void func_0024C7D8(Ref *r, const int *value);
extern "C" void func_0024C808(Ref *r, int in_chrg);

extern "C" void func_002310F0(Obj *self, int value)
{
    Ref *r = &self->ref;
    Ref tmp;
    int v = value;
    func_0024C7D8(&tmp, &v);
    r->assign(tmp);
    func_0024C808(&tmp, 2);
}
