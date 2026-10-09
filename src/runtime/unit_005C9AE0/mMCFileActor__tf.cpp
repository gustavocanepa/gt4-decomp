typedef unsigned int u32;

extern "C" void mFadeActor__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00690CF0[];
extern int D_0088E0B0;

extern int D_0088DC20;

extern "C" void *mMCFileActor__tf(void) {
    if (D_0088DC20 == 0) {
        mFadeActor__tf();
        func_005BFB68(&D_0088DC20, D_00690CF0, &D_0088E0B0);
    }
    return &D_0088DC20;
}
