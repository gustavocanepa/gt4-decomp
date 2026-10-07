typedef unsigned int u32;

extern "C" void func_005EA250();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069CD00[];
extern int D_0088E910;

extern int D_0088E920;

extern "C" void *func_005EA2B0(void) {
    if (D_0088E920 == 0) {
        func_005EA250();
        func_005BFB68(&D_0088E920, D_0069CD00, &D_0088E910);
    }
    return &D_0088E920;
}
