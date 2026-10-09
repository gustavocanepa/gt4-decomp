typedef unsigned int u32;

extern "C" void mData__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E5D0;

extern int D_0088E140;

extern "C" void *mModelMotion__tf(void) {
    if (D_0088E140 == 0) {
        mData__tf();
        func_005BFB68(&D_0088E140, ((char *)"12mModelMotion"), &D_0088E5D0);
    }
    return &D_0088E140;
}
