typedef unsigned int u32;

extern "C" void RaceBarMeter__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F760;

extern int D_0088F910;

extern "C" void *RaceBattleTachometer__tf(void) {
    if (D_0088F910 == 0) {
        RaceBarMeter__tf();
        func_005BFB68(&D_0088F910, ((char *)"20RaceBattleTachometer"), &D_0088F760);
    }
    return &D_0088F910;
}
