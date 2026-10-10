struct Input;
extern "C" void AutomobileDeviceConfig__setDefault(Input *in);

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

extern "C" void RaceInput__getAutomobileConfig(Race *r, Input *in)
{
    AutomobileDeviceConfig__setDefault(in);
    if (!r->paused && r->active) {
        if (r->listener)
            r->listener->notify(in);
    }
}
