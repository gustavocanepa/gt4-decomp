typedef unsigned int u32;

extern "C" void RaceInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2860[];
extern int D_006D6008;

extern int D_0088F720;

extern "C" void *RaceMachineTestInformation__tf(void) {
    if (D_0088F720 == 0) {
        RaceInformation__tf();
        func_005BFB68(&D_0088F720, D_006A2860, &D_006D6008);
    }
    return &D_0088F720;
}
