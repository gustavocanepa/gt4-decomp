typedef unsigned int u32;

extern "C" void RaceRichCountDisplay__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1B38[];
extern int D_0088F520;

extern int D_0088F670;

extern "C" void *RaceLapDisplay__tf(void) {
    if (D_0088F670 == 0) {
        RaceRichCountDisplay__tf();
        func_005BFB68(&D_0088F670, D_006A1B38, &D_0088F520);
    }
    return &D_0088F670;
}
