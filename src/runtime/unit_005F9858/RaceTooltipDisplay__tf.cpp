typedef unsigned int u32;

extern "C" void RaceDisplayObjectBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5FC8;

extern int D_0088F570;

extern "C" void *RaceTooltipDisplay__tf(void) {
    if (D_0088F570 == 0) {
        RaceDisplayObjectBase__tf();
        func_005BFB68(&D_0088F570, ((char *)"18RaceTooltipDisplay"), &D_006D5FC8);
    }
    return &D_0088F570;
}
