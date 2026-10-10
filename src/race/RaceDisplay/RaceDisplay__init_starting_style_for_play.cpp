struct BigData { char pad[0x10140]; };
struct Big : BigData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int mode();
};

struct Obj {
    char pad[0x10];
    Big *big;
};

extern "C" void RaceDisplay__init_starting_style_short_format(Obj *o);
extern "C" void RaceDisplay__init_starting_style_long_format(Obj *o);

extern "C" void RaceDisplay__init_starting_style_for_play(Obj *o) {
    switch (o->big->mode()) {
    case 1:
        return RaceDisplay__init_starting_style_short_format(o);
    case 0:
    case 2:
    case 3:
        return RaceDisplay__init_starting_style_long_format(o);
    }
}
