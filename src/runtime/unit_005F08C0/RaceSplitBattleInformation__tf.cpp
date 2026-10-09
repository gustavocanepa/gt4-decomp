typedef unsigned int u32;

extern "C" void func_005F2A90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EF40;

extern int D_0088EF50;

extern "C" void *RaceSplitBattleInformation__tf(void) {
    if (D_0088EF50 == 0) {
        func_005F2A90();
        func_005BFB68(&D_0088EF50, ((char *)"26RaceSplitBattleInformation"), &D_0088EF40);
    }
    return &D_0088EF50;
}
