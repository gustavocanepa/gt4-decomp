struct Lock { char pad[0x30]; };
struct Owner;

struct Listener {
    virtual void v0();
    virtual void v1();
    virtual void update(Owner *o, float dt);
};

struct Owner {
    char pad[0x6C];
    Lock lock;
    Listener *listener;
    int active;
    int padA4;
    float time;
};

extern "C" void func_00576788(Lock *l);
extern "C" void func_005767C0(Lock *l);

extern "C" void func_00102AA8(Owner *o, float dt) {
    if (o->active) {
        func_00576788(&o->lock);
        o->listener->update(o, dt);
        o->time += dt;
        func_005767C0(&o->lock);
    }
}
