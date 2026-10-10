struct Obj {
    char pad[0xE424];
    void *lock;
};
extern "C" int func_003D8AB0(void *p);
extern "C" void func_0033DEA8(Obj *o, int a, float x);

extern "C" void func_0038B520(Obj *o, int a, float x)
{
    void *p = o->lock;
    if (p && func_003D8AB0(p))
        return;
    return func_0033DEA8(o, a, x);
}
