typedef int s32;

struct PauseBase {
    s32 m0;
    s32 m4;
    PauseBase() __asm__("PauseBase__structor_0");
    virtual ~PauseBase();
};

struct RacePause : PauseBase {
    s32 mC;
    s32 m10;
    s32 m14;
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
    s32 m28;
    s32 m2C;
    s32 m30;
    s32 m34;
    RacePause();
    virtual void virtual_01();
};

RacePause::RacePause() : m10(0), m14(0), m18(0) {
    virtual_01();
    m1C = 1;
    m30 = 1;
    m28 = 0;
    m2C = 0;
    m34 = 0;
}
