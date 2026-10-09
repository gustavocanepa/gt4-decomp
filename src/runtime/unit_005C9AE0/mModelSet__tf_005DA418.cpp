extern "C" void mData__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697E08[];
extern int D_0088E5D0;

extern int D_0088E150;

extern "C" void *mModelSet__tf(void) {
    if (D_0088E150 == 0) {
        mData__tf();
        func_005BFB68(&D_0088E150, D_00697E08, &D_0088E5D0);
    }
    return &D_0088E150;
}
