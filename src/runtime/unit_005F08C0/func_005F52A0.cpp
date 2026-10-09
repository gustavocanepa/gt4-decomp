typedef unsigned int u32;

extern "C" void SceneCameraBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FE20;

extern int D_0088F090;

extern "C" void *func_005F52A0(void) {
    if (D_0088F090 == 0) {
        SceneCameraBase__tf();
        func_005BFB68(&D_0088F090, ((char *)"Q29CameraSys13CameraManager"), &D_0088FE20);
    }
    return &D_0088F090;
}
