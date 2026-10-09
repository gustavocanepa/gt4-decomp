typedef unsigned int u32;

extern "C" void mEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E600;

extern int D_0088E620;

extern "C" void *mFinalizeEvent__tf(void) {
    if (D_0088E620 == 0) {
        mEvent__tf();
        func_005BFB68(&D_0088E620, ((char *)"14mFinalizeEvent"), &D_0088E600);
    }
    return &D_0088E620;
}
