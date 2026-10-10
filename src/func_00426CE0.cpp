struct Input;
extern "C" void func_003F7170(Input *in);

struct Listener {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void notify(Input *in);
};

struct Race {
    char pad[0x194];
    Listener *listener;
    char pad2[0x30];
    int paused;
    int active;
};

extern "C" void func_00426CE0(Race *r, Input *in)
{
    func_003F7170(in);
    if (!r->paused && r->active) {
        if (r->listener)
            r->listener->notify(in);
    }
}
