extern "C" void *func_001792D8(void *h);
extern "C" void func_00179280(void *h, int in_chrg);
extern "C" void func_003285A8(void *obj);
extern "C" void func_003285F8(void *obj);

/* Reference-counted pointer with the inline assignment of 002F8B00. */
struct Ref {
    void *p;
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

struct Owner {
    char pad0[0x10];
    Ref ref;
};

struct Handle {
    Owner *p;
    int pad[3];
};

extern "C" void func_0017A038(Ref *out)
{
    Handle h;
    func_001792D8(&h);
    out->assign(h.p->ref);
    func_00179280(&h, 2);
}
