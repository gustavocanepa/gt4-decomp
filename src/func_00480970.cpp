/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val {
    int type;
    int v;
    Val() { type = 1; }
};

struct Obj {
    char pad[0x5C];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual Val get();
};

extern "C" Obj *func_00480878(int a, int b);

extern "C" Val func_00480970(int a, int b)
{
    Obj *o = func_00480878(a, b);
    if (o)
        return o->get();
    return Val();
}
