struct Target;
extern "C" void func_002C3B60(Target *t, int a);
extern "C" void func_002C3CF8(Target *t, int a, int b, int c, float f);

struct Ref {
    Target *p;
    Target *operator->() const { return p; }
    operator Target *() const { return p; }
};

struct Obj {
    char pad[0x14];
    Ref target;
};

extern "C" void func_0023FAB8(Obj *o, int a, int b, int c, int d, float f)
{
    func_002C3B60(o->target, a);
    func_002C3CF8(o->target, b, c, d, f);
}
