/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Src { char pad[0xC]; short mC; };
struct func_00378CB8 {
    func_00378CB8(const Src *s);
    char pad[0x18C];
};
struct func_00384A60 {
    func_00384A60();
    int d[3];
};
extern "C" void *func_005A48D8(void *p, int c, unsigned int n);

struct Obj {
    char pad0[0xE8];
    int mE8;
    char pad1[0x148 - 0xEC];
    int m148;
    char pad2[0x180 - 0x14C];
    unsigned long m180;
};
struct func_0037DBF8 : func_00378CB8 {
    func_00384A60 a;
    func_00384A60 b;
    char z[12];
    int m1B0;
    func_0037DBF8(const Src *s);
};

func_0037DBF8::func_0037DBF8(const Src *s) : func_00378CB8(s)
{
    func_005A48D8(z, 0, 12);
    Obj *o = (Obj *)this;
    o->m180 &= ~0xFFUL;
    *(int *)&o->pad2[0x184 - 0x14C] = s->mC;
    o->m148 = 7;
    m1B0 = 0;
    o->mE8 = 1;
}
