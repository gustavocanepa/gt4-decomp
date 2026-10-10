struct Obj;

struct Listener {
    virtual void v0();
    virtual void v1(Obj *o);
};

struct Mutex {
    int w[2];
};

struct Obj {
    char pad[0x6C];
    Mutex mutex;
    char pad74[0x28];
    Listener *listener;
    char padA0[8];
    int mA8;
    int mAC;
};

extern "C" void func_00576788(Mutex *m);
extern "C" void func_005767C0(Mutex *m);
extern "C" void func_0010AB68(Obj *o);

extern "C" void func_00102960(Obj *o) {
    Mutex *m = &o->mutex;
    func_00576788(m);
    o->mA8 = 0;
    o->mAC = 0;
    o->listener->v1(o);
    func_005767C0(m);
    func_0010AB68(o);
}
