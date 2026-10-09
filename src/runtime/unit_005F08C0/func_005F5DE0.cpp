typedef unsigned int u32;

extern "C" void func_005F5B70();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F0C0;

extern int D_0088F0F0;

extern "C" void *func_005F5DE0(void) {
    if (D_0088F0F0 == 0) {
        func_005F5B70();
        func_005BFB68(&D_0088F0F0, ((char *)"Q29CameraSys12CameraRideOn"), &D_0088F0C0);
    }
    return &D_0088F0F0;
}
