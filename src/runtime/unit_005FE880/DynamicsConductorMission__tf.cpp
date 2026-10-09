typedef unsigned int u32;

extern "C" void DynamicsConductorTraining__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FA20;

extern int D_0088FA10;

extern "C" void *DynamicsConductorMission__tf(void) {
    if (D_0088FA10 == 0) {
        DynamicsConductorTraining__tf();
        func_005BFB68(&D_0088FA10, ((char *)"24DynamicsConductorMission"), &D_0088FA20);
    }
    return &D_0088FA10;
}
