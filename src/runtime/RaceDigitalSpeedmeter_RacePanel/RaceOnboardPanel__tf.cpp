typedef unsigned int u32;

extern "C" void RacePanel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F5F0;

extern int D_0088F680;

extern "C" void *RaceOnboardPanel__tf(void) {
    if (D_0088F680 == 0) {
        RacePanel__tf();
        func_005BFB68(&D_0088F680, ((char *)"16RaceOnboardPanel"), &D_0088F5F0);
    }
    return &D_0088F680;
}
