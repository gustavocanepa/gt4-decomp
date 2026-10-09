typedef unsigned int u32;

extern "C" void RaceBGMBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5FA0;

extern int D_0088F030;

extern "C" void *RaceBGMPS2__tf(void) {
    if (D_0088F030 == 0) {
        RaceBGMBase__tf();
        func_005BFB68(&D_0088F030, ((char *)"10RaceBGMPS2"), &D_006D5FA0);
    }
    return &D_0088F030;
}
