typedef unsigned int u32;

extern "C" void CameraBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006AA820[];
extern int D_006D6100;

extern int D_0088FE10;

extern "C" void *func_00603CE0(void) {
    if (D_0088FE10 == 0) {
        CameraBase__tf();
        func_005BFB68(&D_0088FE10, D_006AA820, &D_006D6100);
    }
    return &D_0088FE10;
}
