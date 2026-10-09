typedef unsigned int u32;

extern "C" void RaceNetSinglePlayerInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F9C0;

extern int D_0088EFF0;

extern "C" void *RaceNetRallyBattleInformation__tf(void) {
    if (D_0088EFF0 == 0) {
        RaceNetSinglePlayerInformation__tf();
        func_005BFB68(&D_0088EFF0, ((char *)"29RaceNetRallyBattleInformation"), &D_0088F9C0);
    }
    return &D_0088EFF0;
}
