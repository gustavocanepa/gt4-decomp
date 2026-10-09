typedef unsigned int u32;

extern "C" void RaceDisplayBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5F98;

extern int D_0088F330;

extern "C" void *RaceDisplay__tf(void) {
    if (D_0088F330 == 0) {
        RaceDisplayBase__tf();
        func_005BFB68(&D_0088F330, ((char *)"11RaceDisplay"), &D_006D5F98);
    }
    return &D_0088F330;
}
