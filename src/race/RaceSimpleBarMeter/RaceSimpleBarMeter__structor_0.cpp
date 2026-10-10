typedef int s32;

/* The base class (RaceDisplayObjectBase); its constructor is RaceDisplayObjectBase__structor_0. Its vptr sits at 0x14. */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

struct RaceSimpleBarMeter : RaceDisplayObjectBase__structor_0 {
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
    unsigned int color;
    s32 m2C;
    RaceSimpleBarMeter();
    virtual ~RaceSimpleBarMeter();
};

RaceSimpleBarMeter::RaceSimpleBarMeter() {
    color = 0x80C0C0C0;
    m20 = 1;
    m24 = 0x40000000;
    m18 = 0;
    m1C = 0;
    m2C = 0;
}
