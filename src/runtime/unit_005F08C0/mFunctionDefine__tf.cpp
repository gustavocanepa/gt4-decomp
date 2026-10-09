typedef unsigned int u32;

extern "C" void mDefine__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E628[];
extern int D_0088EDF0;

extern int D_0088ED70;

extern "C" void *mFunctionDefine__tf(void) {
    if (D_0088ED70 == 0) {
        mDefine__tf();
        func_005BFB68(&D_0088ED70, D_0069E628, &D_0088EDF0);
    }
    return &D_0088ED70;
}
