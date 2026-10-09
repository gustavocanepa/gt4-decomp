typedef unsigned int u32;

extern "C" void mImageFace__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B470[];
extern int D_0088E6F0;

extern int D_0088E670;

extern "C" void *mFrameImageFace__tf(void) {
    if (D_0088E670 == 0) {
        mImageFace__tf();
        func_005BFB68(&D_0088E670, D_0069B470, &D_0088E6F0);
    }
    return &D_0088E670;
}
