typedef unsigned int u32;

extern "C" void mComposite__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698470[];
extern int D_0088E060;

extern int D_0088E1D0;

extern "C" void *mProject__tf(void) {
    if (D_0088E1D0 == 0) {
        mComposite__tf();
        func_005BFB68(&D_0088E1D0, D_00698470, &D_0088E060);
    }
    return &D_0088E1D0;
}
