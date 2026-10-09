typedef unsigned int u32;

extern "C" void mTransition__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E2F0;

extern int D_0088E4D0;

extern "C" void *mBlockTransition__tf(void) {
    if (D_0088E4D0 == 0) {
        mTransition__tf();
        func_005BFB68(&D_0088E4D0, ((char *)"16mBlockTransition"), &D_0088E2F0);
    }
    return &D_0088E4D0;
}
