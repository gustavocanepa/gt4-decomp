typedef unsigned int u32;

extern "C" void func_005CB130();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A268[];
extern int D_006D5E60;

extern int D_0088E3D0;

extern "C" void *func_005DF780(void) {
    if (D_0088E3D0 == 0) {
        func_005CB130();
        func_005BFB68(&D_0088E3D0, D_0069A268, &D_006D5E60);
    }
    return &D_0088E3D0;
}
