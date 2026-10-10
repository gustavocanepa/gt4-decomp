extern "C" unsigned int func_0057F260(const char *s);
struct String2;
extern "C" String2 *func_005C2630(String2 *str, unsigned int pos, unsigned int n1, const char *s, unsigned int n2);
struct String2 {
    char *dat;
    String2 &replace(unsigned int pos, unsigned int n1, const char *s, unsigned int n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String2 &assign(const char *s, unsigned int n) { return replace(0, (unsigned int)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
};

struct Part;
extern "C" void func_004AFF60(Part *p);
extern "C" char D_0069D820[];

struct Obj {
    char pad[0x14];
    String2 name;
    char part[0xD0];
    int mE8;
    int mEC;
    int mF0;
    int mF4;
};

extern "C" void func_002F71B8(Obj *o)
{
    func_004AFF60((Part *)o->part);
    o->mE8 = 0;
    o->mF0 = 0;
    o->mF4 = 0;
    o->name.assign(D_0069D820);
}
