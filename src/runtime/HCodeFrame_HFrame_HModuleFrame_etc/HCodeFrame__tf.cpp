typedef unsigned int u32;

extern "C" void HFrame__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E500[];
extern int D_006D5F40;

extern int D_0088ECB0;

extern "C" void *HCodeFrame__tf(void) {
    if (D_0088ECB0 == 0) {
        HFrame__tf();
        func_005BFB68(&D_0088ECB0, D_0069E500, &D_006D5F40);
    }
    return &D_0088ECB0;
}
