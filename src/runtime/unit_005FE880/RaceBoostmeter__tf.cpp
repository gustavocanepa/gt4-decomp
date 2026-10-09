typedef unsigned int u32;

extern "C" void RaceRoundMeterBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F750;

extern int D_0088FA40;

extern "C" void *RaceBoostmeter__tf(void) {
    if (D_0088FA40 == 0) {
        RaceRoundMeterBase__tf();
        func_005BFB68(&D_0088FA40, ((char *)"14RaceBoostmeter"), &D_0088F750);
    }
    return &D_0088FA40;
}
