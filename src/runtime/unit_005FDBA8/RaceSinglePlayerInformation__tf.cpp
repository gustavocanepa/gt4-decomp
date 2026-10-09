extern "C" void RaceInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3270[];
extern int D_006D6008;

extern int D_0088F830;

extern "C" void *RaceSinglePlayerInformation__tf(void) {
    if (D_0088F830 == 0) {
        RaceInformation__tf();
        func_005BFB68(&D_0088F830, D_006A3270, &D_006D6008);
    }
    return &D_0088F830;
}
