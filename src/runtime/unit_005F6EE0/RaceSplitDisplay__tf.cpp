typedef unsigned int u32;

extern "C" void RaceSplitDisplayBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F340;

extern int D_0088F350;

extern "C" void *RaceSplitDisplay__tf(void) {
    if (D_0088F350 == 0) {
        RaceSplitDisplayBase__tf();
        func_005BFB68(&D_0088F350, ((char *)"16RaceSplitDisplay"), &D_0088F340);
    }
    return &D_0088F350;
}
