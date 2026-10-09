typedef unsigned int u32;

extern "C" void RaceArcade__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FDB8[];
extern int D_0088F1C0;

extern int D_0088F200;

extern "C" void *RaceArcadeDemo__tf(void) {
    if (D_0088F200 == 0) {
        RaceArcade__tf();
        func_005BFB68(&D_0088F200, D_0069FDB8, &D_0088F1C0);
    }
    return &D_0088F200;
}
