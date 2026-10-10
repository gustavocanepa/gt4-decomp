struct Sub { char pad[0x18]; int m18; };
struct Obj {
    char pad[0x170];
    Sub sub;
    char pad2[0x1B8 - 0x170 - sizeof(Sub)];
    int m1B8;
    char pad3[0x1D8 - 0x1BC];
    int m1D8;
    int m1DC;
};
int RaceInput__getButtonDown(Obj *);

extern "C" void func_00427028(Obj *o)
{
    Sub *s = &o->sub;
    o->m1DC = 0;
    if (o->m1B8 != s->m18) {
        o->m1D8 = 0;
        o->m1DC = RaceInput__getButtonDown(o);
    } else {
        o->m1D8++;
        if (o->m1D8 >= 31 && o->m1D8 - 30 == (o->m1D8 - 30) / 8 * 8)
            o->m1DC = s->m18;
    }
}
