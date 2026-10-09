typedef unsigned int u32;

extern "C" void RaceSinglePlayerInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F830;

extern int D_0088F950;

extern "C" void *RaceTrainingInformation__tf(void) {
    if (D_0088F950 == 0) {
        RaceSinglePlayerInformation__tf();
        func_005BFB68(&D_0088F950, ((char *)"23RaceTrainingInformation"), &D_0088F830);
    }
    return &D_0088F950;
}
