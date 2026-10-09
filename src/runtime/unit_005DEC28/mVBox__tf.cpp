typedef unsigned int u32;

extern "C" void mDBox__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E9C0;

extern int D_0088E9A0;

extern "C" void *mVBox__tf(void) {
    if (D_0088E9A0 == 0) {
        mDBox__tf();
        func_005BFB68(&D_0088E9A0, ((char *)"5mVBox"), &D_0088E9C0);
    }
    return &D_0088E9A0;
}
