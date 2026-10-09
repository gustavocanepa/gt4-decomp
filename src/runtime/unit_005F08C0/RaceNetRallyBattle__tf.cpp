typedef unsigned int u32;

extern "C" void RaceNetSinglePlayer__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F9B0;

extern int D_0088EFE0;

extern "C" void *RaceNetRallyBattle__tf(void) {
    if (D_0088EFE0 == 0) {
        RaceNetSinglePlayer__tf();
        func_005BFB68(&D_0088EFE0, ((char *)"18RaceNetRallyBattle"), &D_0088F9B0);
    }
    return &D_0088EFE0;
}
