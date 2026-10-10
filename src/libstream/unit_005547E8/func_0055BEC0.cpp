struct Chan { int func_005AE360; int pad[4]; int count; };
struct Dev { char pad[0x234]; Chan chan; };
extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" char D_00655340[];

extern "C" int func_0055BEC0(Dev *d)
{
    Chan *c = &d->chan;
    if (!c->func_005AE360)
        return 0;
    func_00576100(D_00655340);
    int n = c->count;
    func_00576140(D_00655340);
    return n;
}
