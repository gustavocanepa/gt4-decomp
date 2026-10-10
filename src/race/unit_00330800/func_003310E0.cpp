struct Obj { int m0[4]; int m10, m14, m18, m1C; };
extern "C" void func_00331170(Obj *);
extern "C" void func_003311B8(Obj *);

extern "C" void func_003310E0(Obj *o)
{
    if (o->m18 == 1 && o->m1C == 1) return;
    func_00331170(o);
    if (o->m18 >= 2) func_003311B8(o);
    o->m10 *= o->m18;
    o->m14 *= o->m1C;
    o->m18 = 1;
    o->m1C = 1;
}
