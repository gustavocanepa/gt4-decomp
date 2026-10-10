/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Src { f32 a, b, c, d, e, f; };
struct Obj { char pad[0x1C]; f32 x, y, z, f28, f2C, w; s32 f34; char pad38[4]; s32 flags; };

extern "C" void func_00400458(Obj *o, const Src *s) {
    o->x = s->a;
    o->y = s->b;
    o->z = s->c;
    o->w = s->d;
    o->f28 = s->e;
    o->f2C = s->f;
    o->flags = (o->flags & 0xFFFF00FF) | 0x100;
    o->f34 = 0;
}
