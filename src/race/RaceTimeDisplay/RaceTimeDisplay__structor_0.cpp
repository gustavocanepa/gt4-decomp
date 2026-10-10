typedef int s32;

/* RaceValueDisplayBase; its constructor is RaceValueDisplayBase__structor_1. The vptr sits at 0x14. */
struct RaceValueDisplayBase__structor_1 {
    char pad[0x14];
    RaceValueDisplayBase__structor_1();
    virtual ~RaceValueDisplayBase__structor_1();
};

struct RaceTimeDisplay : RaceValueDisplayBase__structor_1 {
    s32 color;
    char pad2[0x4C];
    s32 m68;
    s32 m6C;
    RaceTimeDisplay();
    virtual ~RaceTimeDisplay();
};

RaceTimeDisplay::RaceTimeDisplay() : color(0x80C8C8C8), m68(0), m6C(-1) {
}
