typedef unsigned int u32;

extern "C" void DynamicsConductorLicense__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F9F0;

extern int D_0088FA20;

extern "C" void *DynamicsConductorTraining__tf(void) {
    if (D_0088FA20 == 0) {
        DynamicsConductorLicense__tf();
        func_005BFB68(&D_0088FA20, ((char *)"25DynamicsConductorTraining"), &D_0088F9F0);
    }
    return &D_0088FA20;
}
