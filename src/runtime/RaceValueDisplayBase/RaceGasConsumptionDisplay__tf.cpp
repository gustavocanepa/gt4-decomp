typedef unsigned int u32;

extern "C" void RaceValueDisplayBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1AC8[];
extern int D_0088F4A0;

extern int D_0088F4F0;

extern "C" void *RaceGasConsumptionDisplay__tf(void) {
    if (D_0088F4F0 == 0) {
        RaceValueDisplayBase__tf();
        func_005BFB68(&D_0088F4F0, D_006A1AC8, &D_0088F4A0);
    }
    return &D_0088F4F0;
}
