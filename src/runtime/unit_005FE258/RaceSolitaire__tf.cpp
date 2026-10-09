typedef unsigned int u32;

extern "C" void RaceBasic__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F230;

extern int D_0088F8F0;

extern "C" void *RaceSolitaire__tf(void) {
    if (D_0088F8F0 == 0) {
        RaceBasic__tf();
        func_005BFB68(&D_0088F8F0, ((char *)"13RaceSolitaire"), &D_0088F230);
    }
    return &D_0088F8F0;
}
