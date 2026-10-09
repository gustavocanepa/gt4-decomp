typedef unsigned int u32;

extern "C" void RacePS2Base__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A00E0[];
extern int D_0088F020;

extern int D_0088F230;

extern "C" void *RaceBasic__tf(void) {
    if (D_0088F230 == 0) {
        RacePS2Base__tf();
        func_005BFB68(&D_0088F230, D_006A00E0, &D_0088F020);
    }
    return &D_0088F230;
}
