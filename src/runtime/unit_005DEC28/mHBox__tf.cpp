typedef unsigned int u32;

extern "C" void mDBox__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E9C0;

extern int D_0088E6E0;

extern "C" void *mHBox__tf(void) {
    if (D_0088E6E0 == 0) {
        mDBox__tf();
        func_005BFB68(&D_0088E6E0, ((char *)"5mHBox"), &D_0088E9C0);
    }
    return &D_0088E6E0;
}
