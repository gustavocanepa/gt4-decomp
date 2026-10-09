typedef unsigned int u32;

extern "C" void hFunctionValue__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069EFB8[];
extern int D_0088EAB0;

extern int D_0088EEE0;

extern "C" void *hBuiltinFunction__tf(void) {
    if (D_0088EEE0 == 0) {
        hFunctionValue__tf();
        func_005BFB68(&D_0088EEE0, D_0069EFB8, &D_0088EAB0);
    }
    return &D_0088EEE0;
}
