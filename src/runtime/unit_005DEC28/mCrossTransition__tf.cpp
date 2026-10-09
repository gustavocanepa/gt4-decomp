typedef unsigned int u32;

extern "C" void mTransition__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E2F0;

extern int D_0088E5B0;

extern "C" void *mCrossTransition__tf(void) {
    if (D_0088E5B0 == 0) {
        mTransition__tf();
        func_005BFB68(&D_0088E5B0, ((char *)"16mCrossTransition"), &D_0088E2F0);
    }
    return &D_0088E5B0;
}
