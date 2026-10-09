typedef unsigned int u32;

extern "C" void mFBox__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E610;

extern int D_0088E260;

extern "C" void *mScaleBar__tf(void) {
    if (D_0088E260 == 0) {
        mFBox__tf();
        func_005BFB68(&D_0088E260, ((char *)"9mScaleBar"), &D_0088E610);
    }
    return &D_0088E260;
}
