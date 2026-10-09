typedef unsigned int u32;

extern "C" void func_005F32B8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EF70;

extern int D_0088EFC0;

extern "C" void *RaceNetBattleInformation__tf(void) {
    if (D_0088EFC0 == 0) {
        func_005F32B8();
        func_005BFB68(&D_0088EFC0, ((char *)"24RaceNetBattleInformation"), &D_0088EF70);
    }
    return &D_0088EFC0;
}
