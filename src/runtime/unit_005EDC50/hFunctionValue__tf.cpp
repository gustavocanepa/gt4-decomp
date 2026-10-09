typedef unsigned int u32;

extern "C" void hValue__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EE90;

extern int D_0088EAB0;

extern "C" void *hFunctionValue__tf(void) {
    if (D_0088EAB0 == 0) {
        hValue__tf();
        func_005BFB68(&D_0088EAB0, ((char *)"14hFunctionValue"), &D_0088EE90);
    }
    return &D_0088EAB0;
}
