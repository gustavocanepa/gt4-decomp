struct Res;
extern "C" void func_003285A8(Res *r); /* add a reference */
extern "C" void func_003285F8(Res *r); /* drop a reference */

/* A reference-counting pointer, named after its destructor (func_00302A80) so that
   _$_13func_00302A80 resolves. */
struct func_00302A80 {
    Res *p;
    func_00302A80(const func_00302A80 &o);
    ~func_00302A80();
    func_00302A80 &operator=(const func_00302A80 &o)
    {
        if (this != &o) {
            Res *np = o.p;
            if (np)
                func_003285A8(np);
            if (p)
                func_003285F8(p);
            p = np;
        }
        return *this;
    }
};

extern "C" func_00302A80 func_003030D8(int b, int a);

extern "C" void hMethodValue__virtual_08(int a, func_00302A80 *out, int b)
{
    *out = func_003030D8(b, a);
}
