struct Res;
extern "C" void func_003285A8(Res *r); /* add a reference */
extern "C" void func_003285F8(Res *r); /* drop a reference */

/* A reference-counting pointer, named after its destructor (func_00309378) so that
   _$_13func_00309378 resolves. */
struct func_00309378 {
    Res *p;
    func_00309378(const func_00309378 &o);
    ~func_00309378();
    func_00309378 &operator=(const func_00309378 &o)
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

struct Key {
    int id;
};

extern "C" func_00309378 func_0030BA08(int id);

extern "C" void adhoc__getDeepCopy(func_00309378 *self, Key *k)
{
    *self = func_0030BA08(k->id);
}
