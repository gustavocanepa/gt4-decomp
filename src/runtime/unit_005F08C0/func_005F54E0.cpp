typedef unsigned int u32;

extern "C" void func_005F52A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F090;

extern int D_0088F0A0;

extern "C" void *func_005F54E0(void) {
    if (D_0088F0A0 == 0) {
        func_005F52A0();
        func_005BFB68(&D_0088F0A0, ((char *)"Q29CameraSys18PhotoCameraManager"), &D_0088F090);
    }
    return &D_0088F0A0;
}
