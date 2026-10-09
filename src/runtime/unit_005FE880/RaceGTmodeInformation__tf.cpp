typedef unsigned int u32;

extern "C" void RaceInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3EE0[];
extern int D_006D6008;

extern int D_0088F980;

extern "C" void *RaceGTmodeInformation__tf(void) {
    if (D_0088F980 == 0) {
        RaceInformation__tf();
        func_005BFB68(&D_0088F980, D_006A3EE0, &D_006D6008);
    }
    return &D_0088F980;
}
