typedef unsigned int u32;

extern "C" void RaceDriverModel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F690;

extern int D_0088F280;

extern "C" void *RaceCrewModel__tf(void) {
    if (D_0088F280 == 0) {
        RaceDriverModel__tf();
        func_005BFB68(&D_0088F280, ((char *)"13RaceCrewModel"), &D_0088F690);
    }
    return &D_0088F280;
}
