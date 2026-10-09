typedef unsigned int u32;

extern "C" void VehicleModel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5F60;

extern int D_0088F2A0;

extern "C" void *RaceCarModel__tf(void) {
    if (D_0088F2A0 == 0) {
        VehicleModel__tf();
        func_005BFB68(&D_0088F2A0, ((char *)"12RaceCarModel"), &D_006D5F60);
    }
    return &D_0088F2A0;
}
