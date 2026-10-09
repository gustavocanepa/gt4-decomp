typedef unsigned int u32;

extern "C" void RaceBasicWithRaceDisplay__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F220;

extern int D_0088F840;

extern "C" void *RaceSinglePlayer__tf(void) {
    if (D_0088F840 == 0) {
        RaceBasicWithRaceDisplay__tf();
        func_005BFB68(&D_0088F840, ((char *)"16RaceSinglePlayer"), &D_0088F220);
    }
    return &D_0088F840;
}
