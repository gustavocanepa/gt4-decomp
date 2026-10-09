typedef unsigned int u32;

extern "C" void RaceDriverModel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A01E8[];
extern int D_0088F690;

extern int D_0088F280;

extern "C" void *RaceCrewModel__tf(void) {
    if (D_0088F280 == 0) {
        RaceDriverModel__tf();
        func_005BFB68(&D_0088F280, D_006A01E8, &D_0088F690);
    }
    return &D_0088F280;
}
