typedef unsigned int u32;

extern "C" void RaceDisplayDiffEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1378[];
extern int D_0088F390;

extern int D_0088F3A0;

extern "C" void *RaceDisplayGeneralTimeEvent__tf(void) {
    if (D_0088F3A0 == 0) {
        RaceDisplayDiffEvent__tf();
        func_005BFB68(&D_0088F3A0, D_006A1378, &D_0088F390);
    }
    return &D_0088F3A0;
}
