typedef unsigned int u32;

extern "C" void CarGeometryBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0128[];
extern int D_006D5FA8;

extern int D_0088F260;

extern "C" void *MTRGeometry__tf(void) {
    if (D_0088F260 == 0) {
        CarGeometryBase__tf();
        func_005BFB68(&D_0088F260, D_006A0128, &D_006D5FA8);
    }
    return &D_0088F260;
}
