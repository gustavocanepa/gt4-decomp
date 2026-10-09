typedef unsigned int u32;

extern "C" void RaceRoundTachometerBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3DF8[];
extern int D_0088F920;

extern int D_0088F930;

extern "C" void *RaceOnboardTachometer__tf(void) {
    if (D_0088F930 == 0) {
        RaceRoundTachometerBase__tf();
        func_005BFB68(&D_0088F930, D_006A3DF8, &D_0088F920);
    }
    return &D_0088F930;
}
