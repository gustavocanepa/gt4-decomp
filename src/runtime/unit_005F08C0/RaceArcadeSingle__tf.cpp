typedef unsigned int u32;

extern "C" void RaceArcade__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FD70[];
extern int D_0088F1C0;

extern int D_0088F1E0;

extern "C" void *RaceArcadeSingle__tf(void) {
    if (D_0088F1E0 == 0) {
        RaceArcade__tf();
        func_005BFB68(&D_0088F1E0, D_0069FD70, &D_0088F1C0);
    }
    return &D_0088F1E0;
}
