struct Vec4 { float x, y, z, w; };
struct Obj { char pad[0x50]; float radius; };
extern "C" Vec4 func_001041E0(Obj *o);

extern "C" Vec4 func_00104938(Obj *o)
{
    Vec4 v = func_001041E0(o);
    v.w = o->radius;
    return v;
}
