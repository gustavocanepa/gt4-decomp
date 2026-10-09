typedef unsigned int u32;

extern "C" void mStream__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DFF0;

extern int D_0088E160;

extern "C" void *mModelStream__tf(void) {
    if (D_0088E160 == 0) {
        mStream__tf();
        func_005BFB68(&D_0088E160, ((char *)"12mModelStream"), &D_0088DFF0);
    }
    return &D_0088E160;
}
