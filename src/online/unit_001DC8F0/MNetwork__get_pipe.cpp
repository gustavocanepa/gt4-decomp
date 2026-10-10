extern "C" void *func_001DC650(void *h);
extern "C" void func_001DC5F8(void *h, int in_chrg);
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
    char pad0[0x1C0];
    Ref ref;
};

struct Handle {
    Owner *p;
    int pad[3];
};

extern "C" void MNetwork__get_pipe(Ref *out)
{
    Handle h;
    func_001DC650(&h);
    out->assign(h.p->ref);
    func_001DC5F8(&h, 2);
}
