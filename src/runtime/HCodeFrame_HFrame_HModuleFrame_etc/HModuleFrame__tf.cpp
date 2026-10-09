typedef unsigned int u32;

extern "C" void HFrame__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E520[];
extern int D_006D5F40;

extern int D_0088EBD0;

extern "C" void *HModuleFrame__tf(void) {
    if (D_0088EBD0 == 0) {
        HFrame__tf();
        func_005BFB68(&D_0088EBD0, D_0069E520, &D_006D5F40);
    }
    return &D_0088EBD0;
}
