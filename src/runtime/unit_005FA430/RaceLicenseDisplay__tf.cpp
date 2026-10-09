typedef unsigned int u32;

extern "C" void RaceDisplay__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2838[];
extern int D_0088F330;

extern int D_0088F710;

extern "C" void *RaceLicenseDisplay__tf(void) {
    if (D_0088F710 == 0) {
        RaceDisplay__tf();
        func_005BFB68(&D_0088F710, D_006A2838, &D_0088F330);
    }
    return &D_0088F710;
}
