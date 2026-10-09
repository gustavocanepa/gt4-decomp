typedef unsigned int u32;

extern "C" void RaceMeterBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F740;

extern int D_0088F760;

extern "C" void *RaceBarMeter__tf(void) {
    if (D_0088F760 == 0) {
        RaceMeterBase__tf();
        func_005BFB68(&D_0088F760, ((char *)"12RaceBarMeter"), &D_0088F740);
    }
    return &D_0088F760;
}
