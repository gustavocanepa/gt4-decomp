typedef unsigned int u32;

extern "C" void SceneCameraBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F348[];
extern int D_0088FE20;

extern int D_0088F000;

extern "C" void *func_005F36E8(void) {
    if (D_0088F000 == 0) {
        SceneCameraBase__tf();
        func_005BFB68(&D_0088F000, D_0069F348, &D_0088FE20);
    }
    return &D_0088F000;
}
