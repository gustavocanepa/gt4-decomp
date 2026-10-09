typedef unsigned int u32;

extern "C" void hInst__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E6C0[];
extern int D_0088EAC0;

extern int D_0088EC10;

extern "C" void *mLogicalOr__tf(void) {
    if (D_0088EC10 == 0) {
        hInst__tf();
        func_005BFB68(&D_0088EC10, D_0069E6C0, &D_0088EAC0);
    }
    return &D_0088EC10;
}
