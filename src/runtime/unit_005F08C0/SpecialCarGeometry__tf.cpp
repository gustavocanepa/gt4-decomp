typedef unsigned int u32;

extern "C" void CarGeometryBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5FA8;

extern int D_0088F250;

extern "C" void *SpecialCarGeometry__tf(void) {
    if (D_0088F250 == 0) {
        CarGeometryBase__tf();
        func_005BFB68(&D_0088F250, ((char *)"18SpecialCarGeometry"), &D_006D5FA8);
    }
    return &D_0088F250;
}
