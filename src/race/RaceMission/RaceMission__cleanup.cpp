typedef int s32;

extern "C" void RaceBasic__cleanup(void);
extern "C" void func_0038B8D8(void *arg0, s32 arg1);

extern "C" void RaceMission__cleanup(void *arg0) {
    void *s0 = arg0;
    RaceBasic__cleanup();
    func_0038B8D8(s0, 0);
}
