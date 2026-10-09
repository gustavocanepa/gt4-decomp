typedef unsigned int u32;

extern "C" void RaceBGMPS2__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F030;

extern int D_0088F700;

extern "C" void *RaceLicenseBGM__tf(void) {
    if (D_0088F700 == 0) {
        RaceBGMPS2__tf();
        func_005BFB68(&D_0088F700, ((char *)"14RaceLicenseBGM"), &D_0088F030);
    }
    return &D_0088F700;
}
