typedef unsigned int u32;

extern "C" void RaceBasic__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F230;

extern int D_0088EF90;

extern "C" void *func_005F3410(void) {
    if (D_0088EF90 == 0) {
        RaceBasic__tf();
        func_005BFB68(&D_0088EF90, ((char *)"t11RaceBattleT1i6"), &D_0088F230);
    }
    return &D_0088EF90;
}
