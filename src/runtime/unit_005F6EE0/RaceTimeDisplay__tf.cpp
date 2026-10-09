typedef unsigned int u32;

extern "C" void RaceValueDisplayBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A18E8[];
extern int D_0088F4A0;

extern int D_0088F400;

extern "C" void *RaceTimeDisplay__tf(void) {
    if (D_0088F400 == 0) {
        RaceValueDisplayBase__tf();
        func_005BFB68(&D_0088F400, D_006A18E8, &D_0088F4A0);
    }
    return &D_0088F400;
}
