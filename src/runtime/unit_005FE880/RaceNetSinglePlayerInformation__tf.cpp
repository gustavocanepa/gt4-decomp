typedef unsigned int u32;

extern "C" void RaceSinglePlayerInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F830;

extern int D_0088F9C0;

extern "C" void *RaceNetSinglePlayerInformation__tf(void) {
    if (D_0088F9C0 == 0) {
        RaceSinglePlayerInformation__tf();
        func_005BFB68(&D_0088F9C0, ((char *)"30RaceNetSinglePlayerInformation"), &D_0088F830);
    }
    return &D_0088F9C0;
}
