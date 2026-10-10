struct Tm { unsigned short year; unsigned char month, day, hour, min, sec, pad; };
struct Stamp { unsigned char flag, sec, min, hour, day, month; unsigned short year; } __attribute__((aligned(8)));
struct Obj { int m0, m4; Stamp now; Stamp saved; char pad[0x48 - 0x18]; unsigned short flags; };
extern "C" int func_00548918(void);
extern "C" void func_00579BD8(Tm *, int);
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" void func_001CC098(Obj *o)
{
    Tm t;
    func_00579BD8(&t, func_00548918());
    func_005A48D8(&o->now, 0, 0x40);
    o->now.flag = 0;
    o->now.sec = t.sec;
    o->now.min = t.min;
    o->now.hour = t.hour;
    o->now.day = t.day;
    o->now.month = t.month;
    o->now.year = t.year;
    o->saved = o->now;
    o->flags |= 4;
}
