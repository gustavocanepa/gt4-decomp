typedef int s32;
typedef unsigned int u32;

/* The base class RaceDisplayObjectBase; its constructor is RaceDisplayObjectBase__structor_0. Its vptr sits at 0x14. */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

struct RaceTireWearDisplay : RaceDisplayObjectBase__structor_0 {
    s32 m18;
    u32 color;
    s32 items[4];
    RaceTireWearDisplay();
    virtual ~RaceTireWearDisplay();
};

RaceTireWearDisplay::RaceTireWearDisplay() : m18(0), color(0x80877B80) {
    for (int i = 3; i >= 0; i--)
        items[i] = 0;
}
