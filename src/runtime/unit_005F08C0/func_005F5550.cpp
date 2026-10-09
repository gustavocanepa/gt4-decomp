typedef unsigned int u32;

extern "C" void CameraBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6100;

extern int D_0088F0B0;

extern "C" void *func_005F5550(void) {
    if (D_0088F0B0 == 0) {
        CameraBase__tf();
        func_005BFB68(&D_0088F0B0, ((char *)"Q29CameraSys14CameraVariable"), &D_006D6100);
    }
    return &D_0088F0B0;
}
