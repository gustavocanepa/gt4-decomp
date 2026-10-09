typedef unsigned int u32;

extern "C" void RaceSinglePlayer__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3EF8[];
extern int D_0088F840;

extern int D_0088F970;

extern "C" void *RaceGTmode__tf(void) {
    if (D_0088F970 == 0) {
        RaceSinglePlayer__tf();
        func_005BFB68(&D_0088F970, D_006A3EF8, &D_0088F840);
    }
    return &D_0088F970;
}
