typedef unsigned int u32;

extern "C" void RacePanel__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F5F0;

extern int D_0088F440;

extern "C" void *RaceSimplePanel__tf(void) {
    if (D_0088F440 == 0) {
        RacePanel__tf();
        func_005BFB68(&D_0088F440, ((char *)"15RaceSimplePanel"), &D_0088F5F0);
    }
    return &D_0088F440;
}
