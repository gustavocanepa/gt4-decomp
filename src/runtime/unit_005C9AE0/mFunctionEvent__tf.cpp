typedef unsigned int u32;

extern "C" void mEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006977B8[];
extern int D_0088E600;

extern int D_0088E0C0;

extern "C" void *mFunctionEvent__tf(void) {
    if (D_0088E0C0 == 0) {
        mEvent__tf();
        func_005BFB68(&D_0088E0C0, D_006977B8, &D_0088E600);
    }
    return &D_0088E0C0;
}
