typedef unsigned int u32;

extern "C" void RaceRoundMeterBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3DD8[];
extern int D_0088F750;

extern int D_0088F920;

extern "C" void *RaceRoundTachometerBase__tf(void) {
    if (D_0088F920 == 0) {
        RaceRoundMeterBase__tf();
        func_005BFB68(&D_0088F920, D_006A3DD8, &D_0088F750);
    }
    return &D_0088F920;
}
