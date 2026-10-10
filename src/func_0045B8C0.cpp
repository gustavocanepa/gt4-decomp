/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Src { char pad[0xF8A0]; int count; };
struct Obj { Src *src; int count; int m8; };
void func_0045C0F8(Obj *, float);
void func_0045B978(Obj *, int);
void func_0045BAE0(Obj *);

extern "C" void func_0045B8C0(Obj *o, Src *src, int m8)
{
    func_0045C0F8(o, 0.0f);
    o->m8 = m8;
    o->src = src;
    o->count = src->count;
    for (int i = 0; i < o->count; i++) func_0045B978(o, i);
    return func_0045BAE0(o);
}
