struct Entry { int w[15]; };
struct Table { Entry e[2]; int m78; };
extern Table D_0061850C;
struct Ctx { int m0, m4; };
extern "C" void pglPushAttrib(int);
extern "C" void func_004A53F8(void);
extern "C" int func_00105378(Ctx *, Entry *);
extern "C" void func_00105528(Ctx *);
extern "C" void func_00105AD8(Ctx *, Entry *, int, int);
extern "C" void func_001056A0(Ctx *);

extern "C" void func_002180E0(void *self, Ctx *c)
{
    pglPushAttrib(1);
    Entry *e = &D_0061850C.e[D_0061850C.m78];
    func_00105378(c, e);
    c->m4 = 1;
    func_00105528(c);
    func_00105AD8(c, e, 0, 0);
    func_001056A0(c);
    func_004A53F8();
}
