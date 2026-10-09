typedef unsigned int u32;

extern "C" void RaceSinglePlayer__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A26A8[];
extern int D_0088F840;

extern int D_0088F6C0;

extern "C" void *RaceFreePractice__tf(void) {
    if (D_0088F6C0 == 0) {
        RaceSinglePlayer__tf();
        func_005BFB68(&D_0088F6C0, D_006A26A8, &D_0088F840);
    }
    return &D_0088F6C0;
}
