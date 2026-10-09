typedef unsigned int u32;

extern "C" void RaceSolitaire__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F8F0;

extern int D_0088F730;

extern "C" void *RaceMachineTest__tf(void) {
    if (D_0088F730 == 0) {
        RaceSolitaire__tf();
        func_005BFB68(&D_0088F730, ((char *)"15RaceMachineTest"), &D_0088F8F0);
    }
    return &D_0088F730;
}
