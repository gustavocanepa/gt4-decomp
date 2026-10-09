typedef unsigned int u32;

extern "C" void RaceRoundMeterBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3CB8[];
extern int D_0088F750;

extern int D_0088F900;

extern "C" void *RaceOnboardSpeedmeter__tf(void) {
    if (D_0088F900 == 0) {
        RaceRoundMeterBase__tf();
        func_005BFB68(&D_0088F900, D_006A3CB8, &D_0088F750);
    }
    return &D_0088F900;
}
