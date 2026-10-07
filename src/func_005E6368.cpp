typedef unsigned int u32;

extern "C" void func_005E5020();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B828[];
extern int D_0088E580;

extern int D_0088E6F0;

extern "C" void *func_005E6368(void) {
    if (D_0088E6F0 == 0) {
        func_005E5020();
        func_005BFB68(&D_0088E6F0, D_0069B828, &D_0088E580);
    }
    return &D_0088E6F0;
}
