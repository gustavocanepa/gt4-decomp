typedef unsigned int u32;

/* RaceDisplayObjectBase, named after its constructor (RaceDisplayObjectBase__structor_0): vptr after 0x14 bytes of data */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

/* RaceMessageDisplay, named after its constructor (RaceMessageDisplay__structor_1) */
struct RaceMessageDisplay__structor_1 {
    char pad[0x150];
    RaceMessageDisplay__structor_1();
};

extern char D_006A1460[];

struct RaceEventDisplay;
extern "C" void func_003A5268(RaceEventDisplay *self, const char *text, int flags);

struct RaceEventDisplay : RaceDisplayObjectBase__structor_0 {
    char pad18[0x8];
    u32 color;
    char pad24[0x2C];
    RaceMessageDisplay__structor_1 messages[8];
    RaceEventDisplay();
    virtual ~RaceEventDisplay();
    void clear(float t);
};

RaceEventDisplay::RaceEventDisplay() {
    clear(0.0f);
    color = 0x80C8C8C8;
    func_003A5268(this, D_006A1460, 0);
}
