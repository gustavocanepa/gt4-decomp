typedef unsigned int u32;

extern "C" void mActor__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697728[];
extern int D_0088E000;

extern int D_0088E0B0;

extern "C" void *mFadeActor__tf(void) {
    if (D_0088E0B0 == 0) {
        mActor__tf();
        func_005BFB68(&D_0088E0B0, D_00697728, &D_0088E000);
    }
    return &D_0088E0B0;
}
