typedef unsigned int u32;

extern "C" void RaceSolitaire__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A27B8[];
extern int D_0088F8F0;

extern int D_0088F6F0;

extern "C" void *RaceLicense__tf(void) {
    if (D_0088F6F0 == 0) {
        RaceSolitaire__tf();
        func_005BFB68(&D_0088F6F0, D_006A27B8, &D_0088F8F0);
    }
    return &D_0088F6F0;
}
