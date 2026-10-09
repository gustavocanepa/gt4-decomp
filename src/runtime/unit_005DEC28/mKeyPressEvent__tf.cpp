typedef unsigned int u32;

extern "C" void mKeyEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069BC50[];
extern int D_0088E740;

extern int D_0088E750;

extern "C" void *mKeyPressEvent__tf(void) {
    if (D_0088E750 == 0) {
        mKeyEvent__tf();
        func_005BFB68(&D_0088E750, D_0069BC50, &D_0088E740);
    }
    return &D_0088E750;
}
