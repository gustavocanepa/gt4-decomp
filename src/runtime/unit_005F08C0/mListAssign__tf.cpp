typedef unsigned int u32;

extern "C" void hInst__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E690[];
extern int D_0088EAC0;

extern int D_0088EC90;

extern "C" void *mListAssign__tf(void) {
    if (D_0088EC90 == 0) {
        hInst__tf();
        func_005BFB68(&D_0088EC90, D_0069E690, &D_0088EAC0);
    }
    return &D_0088EC90;
}
