typedef unsigned int u32;

extern "C" void RaceArcadeInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F1D0;

extern int D_0088F1F0;

extern "C" void *RaceArcadeDemoInformation__tf(void) {
    if (D_0088F1F0 == 0) {
        RaceArcadeInformation__tf();
        func_005BFB68(&D_0088F1F0, ((char *)"25RaceArcadeDemoInformation"), &D_0088F1D0);
    }
    return &D_0088F1F0;
}
