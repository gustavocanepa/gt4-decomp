typedef unsigned int u32;

extern "C" void RaceMessageDisplay__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1C70[];
extern int D_0088F660;

extern int D_0088F650;

extern "C" void *RaceReplayModeDisplay__tf(void) {
    if (D_0088F650 == 0) {
        RaceMessageDisplay__tf();
        func_005BFB68(&D_0088F650, D_006A1C70, &D_0088F660);
    }
    return &D_0088F650;
}
