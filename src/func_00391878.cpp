typedef int s32;

/* GTSOUNDINSTRUMENT, named after its constructor so that __13func_00462500 resolves */
struct func_00462500 {
    s32 f0;
    char *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    func_00462500();
    virtual ~func_00462500();
};

struct EngineSound : func_00462500 {
    s32 f20;
    char buf[0x100];
    EngineSound();
    virtual ~EngineSound();
};

EngineSound::EngineSound() {
    f0 = 1;
    f4 = buf;
    fC = 0x100;
    f20 = 0;
}
