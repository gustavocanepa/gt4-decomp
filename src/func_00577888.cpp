struct Elem { char pad[0x28]; };
struct Owner { Elem *list; int m4; int m8; };
extern "C" void func_005773B8(Elem *e, int a, int b, int c);
extern "C" int func_00577458(Elem *e);

extern "C" void func_00577888(Owner *o, int a)
{
    Elem *e = o->list;
    if (e == 0) return;
    while (!func_00577458(e))
        func_005773B8(e++, a, o->m4, o->m8);
}
