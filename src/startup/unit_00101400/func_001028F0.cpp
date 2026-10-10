struct Obj;

struct Listener {
    virtual void v00();
    virtual void attached(Obj *o);
};

struct Obj {
    char pad[0x6C];
    char lock[0x30];
    Listener *listener;
};

extern "C" Listener *D_00618498;
extern "C" void func_00576788(void *m);
extern "C" void func_005767C0(void *m);

extern "C" void func_001028F0(Obj *o, Listener *l)
{
    if (!l)
        l = D_00618498;
    o->listener = l;
    func_00576788(o->lock);
    o->listener->attached(o);
    func_005767C0(o->lock);
}
