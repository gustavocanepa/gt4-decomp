typedef unsigned int u32;

extern "C" void RaceTrainingBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3EA0[];
extern int D_0088F960;

extern int D_0088F940;

extern "C" void *RaceTraining__tf(void) {
    if (D_0088F940 == 0) {
        RaceTrainingBase__tf();
        func_005BFB68(&D_0088F940, D_006A3EA0, &D_0088F960);
    }
    return &D_0088F940;
}
