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

struct Source {
    char pad0[0x20];
    void *value;
};

extern "C" Source *func_001D3A60(void);
extern "C" void func_0017E520(Ref *r, void *value);
extern "C" void func_0017D268(Ref *r, int in_chrg);

extern "C" void MMemoryCardManager__getPrintList(Ref *out)
{
    Ref tmp;
    func_0017E520(&tmp, func_001D3A60()->value);
    out->assign(tmp);
    func_0017D268(&tmp, 2);
}
