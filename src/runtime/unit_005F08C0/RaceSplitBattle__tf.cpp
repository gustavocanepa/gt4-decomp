typedef unsigned int u32;

extern "C" void RaceSplitBattleBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F100[];
extern int D_0088EF30;

extern int D_0088EF10;

extern "C" void *RaceSplitBattle__tf(void) {
    if (D_0088EF10 == 0) {
        RaceSplitBattleBase__tf();
        func_005BFB68(&D_0088EF10, D_0069F100, &D_0088EF30);
    }
    return &D_0088EF10;
}
