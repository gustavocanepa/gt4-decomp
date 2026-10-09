typedef unsigned int u32;

extern "C" void CarGeometryBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0150[];
extern int D_006D5FA8;

extern int D_0088F270;

extern "C" void *NormalCarGeometry__tf(void) {
    if (D_0088F270 == 0) {
        CarGeometryBase__tf();
        func_005BFB68(&D_0088F270, D_006A0150, &D_006D5FA8);
    }
    return &D_0088F270;
}
