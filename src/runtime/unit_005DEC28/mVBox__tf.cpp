typedef unsigned int u32;

extern "C" void mDBox__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D1F8[];
extern int D_0088E9C0;

extern int D_0088E9A0;

extern "C" void *mVBox__tf(void) {
    if (D_0088E9A0 == 0) {
        mDBox__tf();
        func_005BFB68(&D_0088E9A0, D_0069D1F8, &D_0088E9C0);
    }
    return &D_0088E9A0;
}
