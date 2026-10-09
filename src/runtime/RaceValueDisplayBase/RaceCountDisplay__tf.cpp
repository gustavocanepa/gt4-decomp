typedef unsigned int u32;

extern "C" void RaceValueDisplayBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1B08[];
extern int D_0088F4A0;

extern int D_0088F460;

extern "C" void *RaceCountDisplay__tf(void) {
    if (D_0088F460 == 0) {
        RaceValueDisplayBase__tf();
        func_005BFB68(&D_0088F460, D_006A1B08, &D_0088F4A0);
    }
    return &D_0088F460;
}
