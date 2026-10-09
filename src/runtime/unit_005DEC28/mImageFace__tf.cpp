typedef unsigned int u32;

extern "C" void mColorFace__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E580;

extern int D_0088E6F0;

extern "C" void *mImageFace__tf(void) {
    if (D_0088E6F0 == 0) {
        mColorFace__tf();
        func_005BFB68(&D_0088E6F0, ((char *)"10mImageFace"), &D_0088E580);
    }
    return &D_0088E6F0;
}
