typedef int s32;

/* RaceValueDisplayBase; its constructor is func_003A4280. The vptr sits at 0x14. */
struct func_003A4280 {
    char pad[0x14];
    func_003A4280();
    virtual ~func_003A4280();
};

struct RaceTimeDisplay : func_003A4280 {
    s32 color;
    char pad2[0x4C];
    s32 m68;
    s32 m6C;
    RaceTimeDisplay();
    virtual ~RaceTimeDisplay();
};

RaceTimeDisplay::RaceTimeDisplay() : color(0x80C8C8C8), m68(0), m6C(-1) {
}
