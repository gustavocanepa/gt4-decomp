typedef unsigned int u32;

extern "C" void func_005F2B30();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EF20;

extern int D_0088EF30;

extern "C" void *RaceSplitBattleBase__tf(void) {
    if (D_0088EF30 == 0) {
        func_005F2B30();
        func_005BFB68(&D_0088EF30, ((char *)"19RaceSplitBattleBase"), &D_0088EF20);
    }
    return &D_0088EF30;
}
