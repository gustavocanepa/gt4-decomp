typedef unsigned int u32;

extern "C" void func_00600610();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FBC0;

extern int D_0088FBD0;

extern "C" void *func_00600718(void) {
    if (D_0088FBD0 == 0) {
        func_00600610();
        func_005BFB68(&D_0088FBD0, ((char *)"Q210GT4_Motion25GeometricFlexibleCallBack"), &D_0088FBC0);
    }
    return &D_0088FBD0;
}
