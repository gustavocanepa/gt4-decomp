struct A { int w[4]; };
struct B { int w[4]; };
struct Obj { char pad[0xC4]; B b; A a; };
extern "C" void *func_004B3C50(A *a);
extern "C" void *func_004B3890(B *b);
extern "C" void func_00575DA0(void *p);
extern "C" void func_004B1710(Obj *self);

extern "C" void func_004B1F38(Obj *self)
{
    B *pb = &self->b; func_00575DA0(func_004B3C50(&self->a)); func_00575DA0(func_004B3890(pb)); func_004B1710(self);
}
