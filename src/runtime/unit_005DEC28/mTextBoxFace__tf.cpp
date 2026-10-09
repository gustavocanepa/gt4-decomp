typedef unsigned int u32;

extern "C" void mScrollable__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D1C8[];
extern int D_0088E910;

extern int D_0088E990;

extern "C" void *mTextBoxFace__tf(void) {
    if (D_0088E990 == 0) {
        mScrollable__tf();
        func_005BFB68(&D_0088E990, D_0069D1C8, &D_0088E910);
    }
    return &D_0088E990;
}
