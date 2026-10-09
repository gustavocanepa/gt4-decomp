typedef unsigned int u32;

extern "C" void RaceSinglePlayerInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FD48[];
extern int D_0088F830;

extern int D_0088F1D0;

extern "C" void *RaceArcadeInformation__tf(void) {
    if (D_0088F1D0 == 0) {
        RaceSinglePlayerInformation__tf();
        func_005BFB68(&D_0088F1D0, D_0069FD48, &D_0088F830);
    }
    return &D_0088F1D0;
}
