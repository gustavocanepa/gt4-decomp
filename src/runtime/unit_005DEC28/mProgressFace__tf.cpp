typedef unsigned int u32;

extern "C" void mImageFace__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E6F0;

extern int D_0088E870;

extern "C" void *mProgressFace__tf(void) {
    if (D_0088E870 == 0) {
        mImageFace__tf();
        func_005BFB68(&D_0088E870, ((char *)"13mProgressFace"), &D_0088E6F0);
    }
    return &D_0088E870;
}
