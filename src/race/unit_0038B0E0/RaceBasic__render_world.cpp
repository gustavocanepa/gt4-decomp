struct Obj {
    char pad[0xE424];
    void *lock;
};
extern "C" int RaceMonitor__isFullScreenMode(void *p);
extern "C" void RacePS2Base__render_world(Obj *o, int a, float x);

extern "C" void RaceBasic__render_world(Obj *o, int a, float x)
{
    void *p = o->lock;
    if (p && RaceMonitor__isFullScreenMode(p))
        return;
    return RacePS2Base__render_world(o, a, x);
}
