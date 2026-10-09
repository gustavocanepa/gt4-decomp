typedef unsigned int u32;

extern "C" void RaceDisplayBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5F98;

extern int D_0088F340;

extern "C" void *RaceSplitDisplayBase__tf(void) {
    if (D_0088F340 == 0) {
        RaceDisplayBase__tf();
        func_005BFB68(&D_0088F340, ((char *)"20RaceSplitDisplayBase"), &D_006D5F98);
    }
    return &D_0088F340;
}
