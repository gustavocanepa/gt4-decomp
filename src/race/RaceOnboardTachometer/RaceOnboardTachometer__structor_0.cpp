typedef int s32;

extern void *RaceOnboardTachometer__vtable;
extern "C" void *RaceRoundTachometerBase__structor_0(void *);
extern "C" void *func_003BE808(void *, float, float);
extern "C" void *func_003BE818(void *, float, float);
extern "C" void *func_003BE828(void *, float, float);
extern "C" void *func_003EC5A8(void *, const char *);

extern "C" void RaceOnboardTachometer__structor_0(void *arg0) {
    RaceRoundTachometerBase__structor_0(arg0);
    *(void **)((char *)arg0 + 0x14) = &RaceOnboardTachometer__vtable;
    func_003BE808(arg0, -1.0000000298f, 15.0000002384f);
    func_003BE818(arg0, 60.0000009537f, 1.0000000298f);
    *(float *)((char *)arg0 + 0x88c) = 0.683333292603f;
    func_003BE828(arg0, 84.0000019073f, 304.000007629f);
    *(float *)((char *)arg0 + 0x50) = -0.309699989855f;
    *(float *)((char *)arg0 + 0x54) = 0.961299970746f;
    func_003EC5A8(arg0, "rev_"); return;
}
