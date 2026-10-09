typedef unsigned int u32;

extern "C" void mRenderContext__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E220;

extern int D_0088E0E0;

extern "C" void *mRenderContextPS2__tf(void) {
    if (D_0088E0E0 == 0) {
        mRenderContext__tf();
        func_005BFB68(&D_0088E0E0, ((char *)"17mRenderContextPS2"), &D_0088E220);
    }
    return &D_0088E0E0;
}
