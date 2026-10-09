typedef unsigned int u32;

extern "C" void RaceInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6008;

extern int D_0088EF70;

extern "C" void *func_005F32B8(void) {
    if (D_0088EF70 == 0) {
        RaceInformation__tf();
        func_005BFB68(&D_0088EF70, ((char *)"t22RaceBattleInformationT1i6"), &D_006D6008);
    }
    return &D_0088EF70;
}
