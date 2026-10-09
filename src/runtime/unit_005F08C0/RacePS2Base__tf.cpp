typedef unsigned int u32;

extern "C" void RaceBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F210;

extern int D_0088F020;

extern "C" void *RacePS2Base__tf(void) {
    if (D_0088F020 == 0) {
        RaceBase__tf();
        func_005BFB68(&D_0088F020, ((char *)"11RacePS2Base"), &D_0088F210);
    }
    return &D_0088F020;
}
