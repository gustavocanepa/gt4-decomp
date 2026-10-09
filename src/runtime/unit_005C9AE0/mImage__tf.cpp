typedef unsigned int u32;

extern "C" void mData__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E5D0;

extern int D_0088E0D0;

extern "C" void *mImage__tf(void) {
    if (D_0088E0D0 == 0) {
        mData__tf();
        func_005BFB68(&D_0088E0D0, ((char *)"6mImage"), &D_0088E5D0);
    }
    return &D_0088E0D0;
}
