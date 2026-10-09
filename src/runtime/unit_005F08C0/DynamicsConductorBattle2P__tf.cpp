typedef unsigned int u32;

extern "C" void DynamicsConductor__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F528[];
extern int D_006D5F80;

extern int D_0088F060;

extern "C" void *DynamicsConductorBattle2P__tf(void) {
    if (D_0088F060 == 0) {
        DynamicsConductor__tf();
        func_005BFB68(&D_0088F060, D_0069F528, &D_006D5F80);
    }
    return &D_0088F060;
}
