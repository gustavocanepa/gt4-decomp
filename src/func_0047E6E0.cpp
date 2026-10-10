typedef unsigned int u32;
struct Color { unsigned char r, g, b, a; int m4; };
extern "C" void func_0047DD60(Color *, u32, u32, u32, u32);
extern "C" int func_0047E658(Color *, int *);

extern "C" void func_0047E6E0(Color *d, Color *o)
{
    func_0047DD60(d, (u32)o->r * d->r >> 7, (u32)o->g * d->g >> 7, (u32)o->b * d->b >> 7, (u32)o->a * d->a >> 7);
    d->m4 = func_0047E658(o, &d->m4);
}
