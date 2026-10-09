typedef unsigned int u32;

extern "C" void HumanModel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5FD0;

extern int D_0088F690;

extern "C" void *RaceDriverModel__tf(void) {
    if (D_0088F690 == 0) {
        HumanModel__tf();
        func_005BFB68(&D_0088F690, ((char *)"15RaceDriverModel"), &D_006D5FD0);
    }
    return &D_0088F690;
}
