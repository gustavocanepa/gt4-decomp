typedef unsigned int u32;

extern "C" void RaceTrainingBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F960;

extern int D_0088F770;

extern "C" void *RaceMission__tf(void) {
    if (D_0088F770 == 0) {
        RaceTrainingBase__tf();
        func_005BFB68(&D_0088F770, ((char *)"11RaceMission"), &D_0088F960);
    }
    return &D_0088F770;
}
