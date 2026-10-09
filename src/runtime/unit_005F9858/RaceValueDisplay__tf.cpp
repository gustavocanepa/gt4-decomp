typedef unsigned int u32;

extern "C" void RaceValueDisplayBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1B50[];
extern int D_0088F4A0;

extern int D_0088F3F0;

extern "C" void *RaceValueDisplay__tf(void) {
    if (D_0088F3F0 == 0) {
        RaceValueDisplayBase__tf();
        func_005BFB68(&D_0088F3F0, D_006A1B50, &D_0088F4A0);
    }
    return &D_0088F3F0;
}
