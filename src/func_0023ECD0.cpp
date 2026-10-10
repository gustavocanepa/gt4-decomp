extern "C" void *func_0023DE48(void *h);
extern "C" void func_0023DDF0(void *h, int in_chrg);
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
    char pad0[0x14];
    Ref ref;
};

struct Handle {
    Owner *p;
    int pad[3];
};

extern "C" void func_0023ECD0(Ref *out)
{
    Handle h;
    func_0023DE48(&h);
    out->assign(h.p->ref);
    func_0023DDF0(&h, 2);
}
