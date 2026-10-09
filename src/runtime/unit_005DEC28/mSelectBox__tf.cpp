typedef unsigned int u32;

extern "C" void mScrollable__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E910;

extern int D_0088E930;

extern "C" void *mSelectBox__tf(void) {
    if (D_0088E930 == 0) {
        mScrollable__tf();
        func_005BFB68(&D_0088E930, ((char *)"10mSelectBox"), &D_0088E910);
    }
    return &D_0088E930;
}
