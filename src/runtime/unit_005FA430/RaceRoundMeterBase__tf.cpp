typedef unsigned int u32;

extern "C" void RaceMeterBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F740;

extern int D_0088F750;

extern "C" void *RaceRoundMeterBase__tf(void) {
    if (D_0088F750 == 0) {
        RaceMeterBase__tf();
        func_005BFB68(&D_0088F750, ((char *)"18RaceRoundMeterBase"), &D_0088F740);
    }
    return &D_0088F750;
}
