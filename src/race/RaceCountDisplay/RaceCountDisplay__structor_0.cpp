extern "C" void *RaceValueDisplayBase__structor_1(void *arg0);
extern "C" char RaceCountDisplay__vtable[];

struct RaceCountDisplay__structor_0_s0 {
    char pad0[0x14];
    void *unk14;
    char pad18[0x50];
    int unk68;
    int unk6C;
};

extern "C" void RaceCountDisplay__structor_0(void *arg0) {
    void *s0 = arg0;
    RaceValueDisplayBase__structor_1(s0);
    ((struct RaceCountDisplay__structor_0_s0 *)s0)->unk6C = 0;
    ((struct RaceCountDisplay__structor_0_s0 *)s0)->unk68 = 0;
    ((struct RaceCountDisplay__structor_0_s0 *)s0)->unk14 = RaceCountDisplay__vtable;
}
