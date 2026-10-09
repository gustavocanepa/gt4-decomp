typedef unsigned int u32;

extern "C" void RaceResultBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3808[];
extern int D_006D6048;

extern int D_0088F8B0;

extern "C" void *ResultArcade__tf(void) {
    if (D_0088F8B0 == 0) {
        RaceResultBase__tf();
        func_005BFB68(&D_0088F8B0, D_006A3808, &D_006D6048);
    }
    return &D_0088F8B0;
}
