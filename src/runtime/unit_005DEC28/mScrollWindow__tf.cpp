typedef unsigned int u32;

extern "C" void mComposite__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E060;

extern int D_0088E8E0;

extern "C" void *mScrollWindow__tf(void) {
    if (D_0088E8E0 == 0) {
        mComposite__tf();
        func_005BFB68(&D_0088E8E0, ((char *)"13mScrollWindow"), &D_0088E060);
    }
    return &D_0088E8E0;
}
