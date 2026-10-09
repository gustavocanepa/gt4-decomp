typedef unsigned int u32;

extern "C" void DynamicsConductorTraining__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A40F8[];
extern int D_0088FA20;

extern int D_0088FA10;

extern "C" void *DynamicsConductorMission__tf(void) {
    if (D_0088FA10 == 0) {
        DynamicsConductorTraining__tf();
        func_005BFB68(&D_0088FA10, D_006A40F8, &D_0088FA20);
    }
    return &D_0088FA10;
}
