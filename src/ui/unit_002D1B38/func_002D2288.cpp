/* compiler: ee-gcc2.96-nosib */
struct Obj { int m0; int m4; int m8; float mC; int m10; float m14; float m18; float m1C; char pad[0x10]; void *m30; };
extern "C" float func_002D2218(Obj *);
extern "C" void func_0025B538(void *, float, float, float, float);

extern "C" void func_002D2288(Obj *o)
{
    if (o->m30) {
        float t = func_002D2218(o);
        float a = o->m1C + o->m14 * t;
        float b = o->mC * t;
        if (o->m4) func_0025B538(o->m30, a, 0.0f, b, o->m18);
        else func_0025B538(o->m30, 0.0f, a, o->m18, b);
    }
}
