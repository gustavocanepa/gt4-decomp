typedef unsigned int u32;

extern "C" void RaceBarMeter__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3E10[];
extern int D_0088F760;

extern int D_0088F910;

extern "C" void *RaceBattleTachometer__tf(void) {
    if (D_0088F910 == 0) {
        RaceBarMeter__tf();
        func_005BFB68(&D_0088F910, D_006A3E10, &D_0088F760);
    }
    return &D_0088F910;
}
