typedef unsigned int u32;

extern "C" void hInst__tf();
extern "C" void func_005C0E78(void *a0, void *a1, void *a2);

extern char D_0069D788[];
extern int D_0088EAC0;

extern int D_0088EA50;

extern "C" void *func_005EE2B0(void) {
    if (D_0088EA50 == 0) {
        hInst__tf();
        func_005C0E78(&D_0088EA50, D_0069D788, &D_0088EAC0);
    }
    return &D_0088EA50;
}
