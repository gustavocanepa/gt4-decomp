extern "C" void *func_002E4BD8(void *h);
extern "C" void func_002E4B80(void *h, int in_chrg);
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
    char pad0[0xBC];
    Ref ref;
};

struct Handle {
    Owner *p;
    int pad[3];
};

extern "C" void func_002E50E0(Ref *out)
{
    Handle h;
    func_002E4BD8(&h);
    out->assign(h.p->ref);
    func_002E4B80(&h, 2);
}
