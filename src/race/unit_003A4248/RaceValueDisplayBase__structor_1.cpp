struct RaceDisplayObjectBase {
    char data[0x14];
    virtual ~RaceDisplayObjectBase();
    RaceDisplayObjectBase() __asm__("RaceDisplayObjectBase__structor_0");
};

/* Named after its constructor so that the call resolves. */
struct func_003A9758 {
    char data[0x1C];
    func_003A9758();
    void fadein(float t) __asm__("AutomaticFader__fadein");
};

struct RaceValueDisplayBase : RaceDisplayObjectBase {
    unsigned int color0;
    unsigned int color1;
    int m20;
    int m24;
    func_003A9758 fader;
    unsigned char m44;
    unsigned char m45;
    RaceValueDisplayBase();
    virtual ~RaceValueDisplayBase();
    void setName(const char *name) __asm__("func_003A4308");
};

extern const char D_006A1458[];

RaceValueDisplayBase::RaceValueDisplayBase() : color0(0x80C8C8C8), color1(0x80B3B3B3), m20(0), m24(0) {
    m44 = 0;
    m45 = 0;
    setName(D_006A1458);
    fader.fadein(0.0f);
}
