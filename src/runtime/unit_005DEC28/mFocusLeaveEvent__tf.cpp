typedef unsigned int u32;

extern "C" void mCrossingEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E5C0;

extern int D_0088E660;

extern "C" void *mFocusLeaveEvent__tf(void) {
    if (D_0088E660 == 0) {
        mCrossingEvent__tf();
        func_005BFB68(&D_0088E660, ((char *)"16mFocusLeaveEvent"), &D_0088E5C0);
    }
    return &D_0088E660;
}
