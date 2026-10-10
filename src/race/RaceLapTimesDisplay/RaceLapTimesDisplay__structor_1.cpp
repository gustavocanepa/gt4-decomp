typedef int s32;

/* The base class; its constructor is RaceDisplayObjectBase__structor_0. Its vptr sits at 0x14. */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

struct RaceLapTimesDisplay__vtable;
extern "C" void func_003A4650(RaceLapTimesDisplay__vtable *);

/* Named after its vtable so the compiler-made vptr store _vt$10D_0067F8A8 resolves. */
struct RaceLapTimesDisplay__vtable : RaceDisplayObjectBase__structor_0 {
    char pad18[0x8];
    s32 m20;
    char pad24[0x20];
    float m44;
    RaceLapTimesDisplay__vtable();
    virtual ~RaceLapTimesDisplay__vtable();
};

RaceLapTimesDisplay__vtable::RaceLapTimesDisplay__vtable() {
    func_003A4650(this);
    m20 = 3;
    m44 = 0.9f;
}
