typedef unsigned int u32;

extern "C" void RaceSolitaireInformation__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A26E8[];
extern int D_0088F8D0;

extern int D_0088F6E0;

extern "C" void *RaceFreeRunInformation__tf(void) {
    if (D_0088F6E0 == 0) {
        RaceSolitaireInformation__tf();
        func_005BFB68(&D_0088F6E0, D_006A26E8, &D_0088F8D0);
    }
    return &D_0088F6E0;
}
