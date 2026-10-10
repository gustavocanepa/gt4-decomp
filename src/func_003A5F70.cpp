typedef int s32;
typedef unsigned int u32;

/* The base class RaceDisplayObjectBase; its constructor is func_003AEBA8. Its vptr sits at 0x14. */
struct func_003AEBA8 {
    char pad[0x14];
    func_003AEBA8();
    virtual ~func_003AEBA8();
};

struct RaceTireWearDisplay : func_003AEBA8 {
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
