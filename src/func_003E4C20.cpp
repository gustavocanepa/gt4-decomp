struct Vec3 { float x, y, z; };
struct Elem { char pad[0x90]; float radius; char pad2[0xA0 - 0x94]; };
struct Table { char pad[0x20]; Elem e[1]; };
extern Table *D_006D6054;
struct Obj { char pad[0x10]; Vec3 pos; char pad2[0x44 - 0x1C]; unsigned char idx; };
int func_0049B330(const Vec3 &, const Vec3 &);

extern "C" bool func_003E4C20(Obj *o)
{
    Elem *e = D_006D6054->e;
    e += o->idx;
    float r = e->radius;
    Vec3 min, max;
    min.x = o->pos.x - r; min.y = o->pos.y - r; min.z = o->pos.z - r;
    max.x = o->pos.x + r; max.y = o->pos.y + r; max.z = o->pos.z + r;
    return func_0049B330(min, max);
}
