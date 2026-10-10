struct Ctx { char pad[0x5B7]; unsigned char paused; };
struct Clock { char pad[0x968]; int start; };
struct Obj {
    Clock *clock;
    char pad[0xCBDC - 4];
    unsigned char frozen;
};
extern "C" Ctx *func_0034C190(Obj *o, int a);
extern "C" void RaceDisplayTimeDiffEvent__structor_0(Clock *c, int a, int dt);

extern "C" void DynamicsConductor__ReportDifferenceFromRecord(Obj *o, int a, int t)
{
    if (o->frozen)
        return;
    if (func_0034C190(o, a)->paused)
        return;
    Clock *c = o->clock;
    if (c->start != 0x157529FF)
        RaceDisplayTimeDiffEvent__structor_0(c, a, t - c->start);
}
